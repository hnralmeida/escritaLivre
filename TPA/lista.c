/*
=========================================================================================
AUTORES: 	
			Henrique Almeida de Oliveira
			Luiz Eduardo Marchiori
Disciplina: Tópicos de Programação Avançada

Implementação de sentinelaSimples.h
=========================================================================================
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "lista.h"

/*
=========================================================================================
			Implementação de sentinelaSimples.h
*/


// inicializa lista com ponteiros nulos
void initializeList(Tlist *list){
	list->first=NULL;
	list->last=NULL;
	list->total=0;
}

void addIn(Tlist * list, int value){
	Tnode *newNode = (Tnode *)malloc(sizeof(Tnode));
	int flag=1;
	newNode->value = value;
	newNode->next = NULL;
	
	if(list->first == NULL){
		//Lista VAZIA: inserir o primeiro N?.
		list->first = newNode;
		list->last = newNode;
	} else {
		//Lista possui pelo menos um N?: Inserir dados em
		//ordem crescente.
		Tnode *actual = list->first;
		Tnode *previous = NULL;
		
		while(actual != NULL){
			if (actual->value >= newNode->value){
				newNode->next = actual;
				if (previous == NULL){
					list->first = newNode;	
				} else{
					previous->next = newNode;
				}
				flag=0;
			}else{
				previous = actual;
				actual = actual->next;
			}
		}
		if(flag){
			Tnode *last = list->last;
			last->next = newNode;
			list->last = newNode;
		}
	}//if ... else
	
	list->total++;
}

// adiciona curso passada como parâmetro na lista 
void addElement(Tlist *list){
	int value;
	
	printf("\n\n\n");
	printf("\t=====| INSERE NOVO NO |=====\n\n");
	printf("Informe valor: ");
	scanf("%d", &value);
	
	addIn(list, value);
}

// imprimir valores na lista
void printList(Tlist *list){
	int i=0;
	Tnode *cell = list->first;
	printf("\nImprimindo um total de %d valores da Lista:\n", list->total);
	while (cell!=NULL){
		printf("[%d]: %d \n", i++, cell->value);
		cell = cell->next;
	}
}

void removeIn(Tlist * list, int value){

	Tnode *actual = list->first, *prev = NULL, *next;
	int removed = 0;

	if(actual == NULL){
		 next = NULL;
	}else{
		next = actual->next;
	}

	while(actual != NULL){
	   if(actual->value==value){
	   	  next = actual->next;
	   	  if(prev == NULL) list->first = next;
	   	  else prev->next = next;
		  free(actual);
		  list->total--;
		  removed = 1;
		  break;
	   }//if
	   prev = actual;
	   actual = actual->next;
	   if(actual != NULL) next = actual->next;
	   else next = NULL;
	}//while
	
	if(removed){
		printf("\n\n\n");
		printf("+--------------------------------------+\n");
		printf("|  AVISO:                              |\n");
		printf("|                                      |\n");
		printf("|  No REMOVIDO com SUCESSO !!!         |\n");
		printf("|                                      |\n");
		printf("+--------------------------------------+\n\n\n");
		
	} else {
		printf("\n\n\n");
		printf("+--------------------------------------+\n");
		printf("|  ALERTA:                             |\n");
		printf("|                                      |\n");
		printf("|  No NAO ENCONTRADO e nem REMOVIDO!!! |\n");
		printf("|                                      |\n");
		printf("+--------------------------------------+\n\n\n");

	}
}

// remover valores da lista
void removeElement(Tlist *list){

	int value;
	
	printf("\n\n\t=====| REMOVER No |=====\n\n");
	printf("\tInforme VALOR a ser REMOVIDO: ");
	scanf("%s", &value);

	removeIn(list, value);
}
