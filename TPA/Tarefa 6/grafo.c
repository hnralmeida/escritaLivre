/*
=========================================================================================
AUTOR: 	Henrique Almeida de Oliveira
Disciplina: Tecnicas de Programacao Avancada
Professor: Eduardo Max Amaral
=========================================================================================
*/

#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>
#include "grafo.h"

/*
=========================================================================================
			Implementacao

typedef struct adjacent{
    Tvertex* vertex;
    int distance;
}Tadjacent;

typedef struct vertex {
	string city_name;
	Tadjacent* adjacent;
    int number_adjacent;
}Tvertex;

typedef struct list {
	Tvertex* item;
	Tlist* next;
}Tlist;

typedef struct graph {
	int total;
	Tlist* list;
}Tgraph;
*/

// Funcao padrao, tira caracteres indesejados para leitura de strings
void limparBuffer(){
    char c;
    while((c= getchar()) != '\n' && c != EOF);
}

void inicitializeGraph(Tgraph* g){
	g->total = 0;
	g->list = NULL;
}

Tvertex* searchCity(Tlist* v, string name){

	if(v == NULL) return NULL;
	printf("\nin");
	Tlist* aux = v;

	while(aux!=NULL){
		if(strcmp(name, aux->item->city_name)!=0)
			aux = aux->next;
		else
			return aux->item;
	}
	printf("\nout of while");
	return NULL;
} 

void insertList(Tlist* v, string name){
	Tvertex *newCity = (Tvertex *)malloc(sizeof(Tvertex));
	newCity->number_adjacent = 0;
	strcpy(newCity->city_name, name);

	Tlist *newNode = (Tlist *)malloc(sizeof(Tlist));
	newNode->item = newCity;
	newNode->next = NULL;
	int flag=1;
	
	// Inserir dados em ordem crescente.	
	if(v == NULL){
		v->item = newCity;
		v->next = NULL;
	}else{
		Tlist *actual = v;
		Tlist *previous = NULL;

		while(actual != NULL && strcmp(name, actual->item->city_name)>0 ){
			previous = actual;
			actual = actual->next;
		}	
		
		if (actual == NULL)
			previous->next = newNode;
		else{
			newNode->next = actual;
			previous->next = newNode;
		}
	}
}

void insertCity(Tgraph* g){
	string name;
	Tvertex* valid = NULL;

	// recebe dados do usuario
	printf("\nDigite o nome da cidade para adicionar: ");
	scanf("%s", name);

	// verifica se ja nao existe o valor passado na arvore
	/*
	printf("\nlooking");
	if(g->list!=NULL) valid = searchCity(g->list, name); 
	else valid = NULL;
	printf("\nfind");
	*/
	if (valid == NULL) {
		printf("\nadd");
		insertList(g->list, name); // se nao estiver adicionado, adiciona o registro
		g->total++;
	}else printf("Valor ja existe na lista");
}

void printCity(Tgraph* g){
	Tlist* v = g->list;
	while(v != NULL){
		printf("\n- %s", v->item->city_name);
		v = v->next;
	}
}