/*
=========================================================================================
AUTORES: 	Henrique Almeida de Oliveira
			Luiz Eduardo Marchiori
Disciplina: Tópicos de Programação Avançada
Professor: 
Implementação de sentinelaSimples.h
=========================================================================================
*/

#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>
#include "sentinelaSimples.h"

/*
=========================================================================================
			Implementação de sentinelaSimples.h
*/


// inicializa lista com ponteiros nulos
void initializeList(list *L){
	L->first=NULL;
	L->last=NULL;
	L->total=0;
}

void addIn(list *L, int value){
	node *newNode = (node *)malloc(sizeof(node));
	int flag=1;
	newNode->value = value;
	newNode->next = NULL;
	
	if(L->first == NULL){
		//Lista VAZIA: inserir o primeiro N?.
		L->first = newNode;
		L->last = newNode;
	} else {
		//Lista possui pelo menos um N?: Inserir dados em
		//ordem crescente.
		node *actual = L->first;
		node *previous = NULL;
		
		while(actual != NULL){
			if (actual->value >= newNode->value){
				newNode->next = actual;
				if (previous == NULL){
					L->first = newNode;	
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
			node *last = L->last;
			last->next = newNode;
			L->last = newNode;
		}
	}//if ... else
	
	L->total++;
}

// adiciona curso passada como parâmetro na lista 
void addElement(list *L){
	int value;
	
	printf("\n\n\n");
	printf("\t=====| INSERE NOVO NO |=====\n\n");
	printf("Informe valor: ");
	scanf("%d", &value);
	
	addIn(L, value);
}

// imprimir valores na lista
void printList(list L){
	int i=0;
	node *cell = L.first;
	printf("\nImprimindo um total de %d valores da Lista:\n", L.total);
	while (cell!=NULL){
		printf("[%d]: %d \n", i++, cell->value);
		cell = cell->next;
	}
}

