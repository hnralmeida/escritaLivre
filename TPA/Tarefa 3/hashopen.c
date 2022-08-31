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

void initializeDB(HashTable *list, FILE* f, int size){
	int reg;

	// Percorre todo arquivo pegando dados do aluno
	while (!feof(f)){
		// Toda linha par eh o numero de uma matricula
		fscanf(f, "%d", &reg);
		addIn(list, reg);
  	}//while
}


void initializeList(HashTable *list, int size){
	list->size = size;
	list->total=0;
	list->vetor = (Tnode*) malloc( size* sizeof(Tnode) );
}

void rehash(HashTable *list, int reg, int co){
	int h2 = 1 + (reg%list->size);
	int h = (co + h2) % list->size;
	Tnode* vetor = list->vetor;

	if(!(list->vetor[h].flag)){
		vetor[h].reg = reg;
		vetor[h].flag = 1;
	}else{
		rehash(list, reg, 1);
	}
}

void addIn(HashTable * list, int reg){
	// Inicializar um novo node com os dados passados
	Tnode* vetor = list->vetor;
	int h = reg % list->size;
	
	if(!(list->vetor[h].flag)){
		vetor[h].reg = reg;
		vetor[h].flag=1;
	}else{
		rehash(list, reg, 1);
	}
	list->total++;
}

void addElement(HashTable *list){
	int reg;
	
	// Consulta no terminal o Aluno a ser adicionado 
	printf("\n\n\n");
	printf("\t=====| INSERE NOVO NO |=====\n\n");
	printf("Informe valor: ");
	scanf("%d", &reg);

	// Adiciona na lista o Aluno passado no terminal
	addIn(list, reg);
}

void printHashTable(HashTable *list){
	int i=0;
	Tnode* vetor = list->vetor;

	// Percorre toda a lista imprimindo aluno
	for (i=0; i<list->size; i++){
		if(!vetor[i].flag) printf(" -> %d", vetor[i].reg);
		else printf(" -");
	}//for
}
/*
void removeIn(HashTable * list, int reg){

	Tnode *actual = list->first, *prev = NULL;
	string removed_name;
	int removed_reg;
	int removed = 0;

	if(actual == NULL)
		// Se node atual for vazio nao percorre nada
		printf("\nNao ha nada para remover na lista");
	else{
		// Percorre toda lista procurando a matricula
		while(actual != NULL && (actual->reg != reg)){
			prev = actual;
			actual = actual->next;
		}//while

		// Se a matricula existir, salva os dados removidos
		if(actual!=NULL){
			strcpy(removed_name, actual->name);
			removed_reg = actual->reg;
			removed = 1;
			list->total--;
		}else {
			printf("Esse elemento nao existe");
			return;
		}//if ... else
		
		//verificar se remover o ultimo
		if(actual->next == list->last){ 
			prev->next = NULL;
			list->last = prev;
			free(actual);
		}else if(prev == NULL){ // verificar se remover o primeiro;
			prev = actual->next;
			list->first = prev;
			free(actual);
		}else{ // caso remover algum do meio qualquer
			prev->next = actual->next;
			free(actual);
		}//if ... else

	}//if ... else
	
	// a flag removed indica ... se algo foi removido da lista
	if(removed){
		printf("\n\n\n");
		printf("\n+--------------------------------------+");
		printf("\n\tAVISO:");
		printf("\n\t%s", removed_name);
		printf("\n\t%d", removed_reg);
		printf("\n\tREMOVIDO com SUCESSO !!!\t");
		printf("\n+--------------------------------------+\n\n\n");
	} else {
		printf("\n\n\n");
		printf("+--------------------------------------+\n");
		printf("|  ALERTA:                             |\n");
		printf("|                                      |\n");
		printf("|  No NAO ENCONTRADO e nem REMOVIDO!!! |\n");
		printf("|                                      |\n");
		printf("+--------------------------------------+\n\n\n");

	}//if ... else
}

void removeElement(HashTable *list){

	int reg;
	
	printf("\n\n\t=====| REMOVER No |=====\n\n");
	printf("\tInforme VALOR a ser REMOVIDO: ");
	scanf("%d", &reg);

	// Remove a matricula indicada no terminal da lista 
	removeIn(list, reg);
}
*/