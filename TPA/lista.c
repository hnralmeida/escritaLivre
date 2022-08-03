/*
=========================================================================================
AUTORES: 	Henrique Almeida de Oliveira
			Luiz Eduardo Marchiori
Disciplina: Tópicos de Programação Avançada
Professor: 
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
void initializeList(List *list){
	list->first=NULL;
	list->last=NULL;
	list->total=0;
}

void addIn(List * list, int value){
	Node *newNode = (Node *)malloc(sizeof(Node));
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
		Node *actual = list->first;
		Node *previous = NULL;
		
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
			Node *last = list->last;
			last->next = newNode;
			list->last = newNode;
		}
	}//if ... else
	
	list->total++;
}

// adiciona curso passada como parâmetro na lista 
void addElement(List *list){
	int value;
	
	printf("\n\n\n");
	printf("\t=====| INSERE NOVO NO |=====\n\n");
	printf("Informe valor: ");
	scanf("%d", &value);
	
	addIn(list, value);
}

// imprimir valores na lista
void printList(List *list){
	int i=0;
	Node *cell = list->first;
	printf("\nImprimindo um total de %d valores da Lista:\n", list->total);
	while (cell!=NULL){
		printf("[%d]: %d \n", i++, cell->value);
		cell = cell->next;
	}
}
