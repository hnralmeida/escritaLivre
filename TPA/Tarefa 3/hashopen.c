/*
=========================================================================================
AUTOR:	Henrique Almeida de Oliveira
Disciplina: Topicos de Programacao Avancada

					Trabalho 01 � Tabela Hash

Implementacao de lista.h
=========================================================================================
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include "hashopen.h"

/*
=========================================================================================
			Implementacao de lista.h
*/

int calcSize(FILE* f){
	int i=0;
	char s[40];

	// Move o cursor para o inicio do arquivo
	fseek(f, 0, SEEK_SET);

	// Percorre todas linhas do arquivo e adiciona 1 no contador 
	// para cada linha percorrida
	while (!feof(f)){
      	fscanf(f, " %[^\n]s", s);
    	i++;
  	}//while

	// Move o cursor para o inicio do arquivo
	fseek(f, 0, SEEK_SET);

	return i;
}

void initializeDB(hashTable *list, FILE* f){
	int reg;

	// Percorre todo arquivo pegando dados do aluno
	while (!feof(f)){
		// Toda linha par eh o numero de uma matricula
		fscanf(f, "%d", &reg);
		addIn(list, reg);
  	}//while
}

void initializeList(hashTable *list, int size){
	list->size = size;
	list->total = 0;
	list->vetor = (Tnode**) malloc( size * sizeof(Tnode*) );
	for(int i=0; i<size; i++) list->vetor[i] = NULL;
}

int rehash(hashTable *list, int reg, int co){
	int h2 = 1 + (reg%list->size);
	int h = (co + h2) % list->size;
	Tnode** vetor = list->vetor;

	if(vetor[h]!=NULL){
		if(!(vetor[h]->flag)){
			vetor[h]->flag = 1;
			vetor[h]->reg = reg;
			return h;
		}else{
			rehash(list, reg, (++co));
		}
	}else{
		Tnode* newNode = (Tnode*)malloc(sizeof(Tnode));
		newNode->flag=1;
		newNode->reg=reg;
		vetor[h]=newNode;
		return h;
	}
}

void addIn(hashTable * list, int reg){
	// Inicializar um novo node com os dados passados
	Tnode** vetor = list->vetor;
	int h = reg % list->size;
	
	if(vetor[h]!=NULL){
		if(!(list->vetor[h]->flag)){
			vetor[h]->reg = reg;
			vetor[h]->flag=1;
		}else{
			h= rehash(list, reg, 1);
		}
	}else{
		Tnode* newNode = (Tnode*)malloc(sizeof(Tnode));
		newNode->flag=1;
		newNode->reg=reg;
		vetor[h]=newNode;
	}
	//printf("\nRegister %d added\n", vetor[h]->reg);
	list->total++;
}

void addElement(hashTable *list){
	int reg;
	
	// Consulta no terminal o Aluno a ser adicionado 
	printf("\n\n\n");
	printf("\t=====| INSERE NOVO NO |=====\n\n");
	printf("Informe valor: ");
	scanf("%d", &reg);

	Tnode* valid=NULL;
	valid = searchTnode(list, reg);
	if(valid!=NULL && valid->flag){
		printf("\nRegistro ja existe");
		return;
	}

	// Adiciona na lista o Aluno passado no terminal
	addIn(list, reg);
}

void printHashTable(hashTable *list){
	int i=0;
	Tnode** vetor = list->vetor;

	// Percorre toda a lista imprimindo aluno
	for (i; i<(list->size); i++){
		if(vetor[i]!=NULL){
			if(vetor[i]->flag) printf("\n -> %d", vetor[i]->reg);
			else printf("\n -");
		}else printf("\n -");
	}//for
	printf("\n\n");
}

Tnode*reSearch(hashTable* list, int reg, int co){
	int h2 = 1 + (reg%list->size);
	int h = (co + h2) % list->size;
	Tnode* node;

	// Condicao de parada
	if(h == (h2-1));

	Tnode** vetor = list->vetor;
	if(vetor[h]!=NULL) {
		if (vetor[h]->reg == reg) return vetor[h];
		node = reSearch(list, reg, ++co);
	}else return NULL;

}

Tnode* searchTnode(hashTable *list, int reg){
	int h = (int) (reg % list->size);
	Tnode** vetor = list->vetor;
	Tnode* node;

	// Percorre toda lista da tabela com o respectivo resto
	if(vetor[h]!=NULL) {
		if (vetor[h]->reg == reg) return vetor[h];
		node = reSearch(list, reg, 1);
	}else return NULL;
	return node;

}

void searchStudent(hashTable *list){
	int reg;
	float init = (float) clock();
	
	printf("\n\n\t=====| PROCURAR No |=====\n\n");
	printf("\tInforme MATRICULA a ser PROCURADA: ");
	scanf("%d", &reg);

	// Procura na lista correspondete da tabela hash pela matricula 
	int rest = (int) (reg % list->size);
	Tnode *node = searchTnode(list, reg);

	// Se o aluno existr (se existir matricula cadastrada) imprime Aluno
	if(node!=NULL) {
		printf("\t+-------------------------------------------------+");
		printf("\n\t\tRegistro: %d\n", node->reg);
		printf("\t+-------------------------------------------------+");
	}else{
		printf("\t+-------------------------------------------------+");
		printf("\n\t\tMatricula não encontrada");
		printf("\n\t+-------------------------------------------------+");
	}//if
	float end = (float) clock();
	float delta = (end-init)/1000;
	printf("\n\nEssa procura levou %.2fms", delta);
}