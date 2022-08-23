/*
=========================================================================================
AUTORES: 	
			Henrique Almeida de Oliveira
			Luiz Eduardo Marchiori
Disciplina: Topicos de Programacao Avancada

Implementação de sentinelaSimples.h
=========================================================================================
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "lista.h"

/*
=========================================================================================
			Implementacao de hash.h
*/

/* Procura na tabela hash pela matricula informada
	0 - nao existe registro // 1 - existe registro
*/
int searchReg(Tlist list[], unsigned long long int reg, unsigned long long int size){
	int i = 0;
	int rest = (int) (reg % size);
	Tlist *auxSec = &(list[rest]);
	Tnode *aux = auxSec->first;
	
	while (aux!=NULL){
		if (reg == aux->reg) return 1;
		aux = aux->next;
	}
	return 0;
}

/* Procura na tabela hash pela matricula informada e retorna seu node */
Tnode* searchTnode(Tlist list[], unsigned long long int reg, unsigned long long int size){
	int i = 0;
	int rest = (int) (reg % size);
	Tlist *auxList = &list[rest];
	Tnode *aux = auxList->first;

	while (aux!=NULL){
		if (reg == aux->reg) return aux;
		aux = aux->next;
	}
	return NULL;

}

void addElementHash (Tlist list[], unsigned long long int size){
	unsigned long long int reg=0;
	string name;
	
	printf("\n\n\n");
	printf("\t=====| INSERE NOVO NO |=====\n\n");

	while(!reg){
		printf("Informe número da matrícula: ");
		scanf("%llu", &reg);
		
		printf("\nInforme nome do aluno: ");
		scanf(" %[^\n50]s", name);

		if(searchReg(list, reg, size)) {
			Tnode* aux = searchTnode(list, reg, size);
			printf("\nMatricula %llu ja cadastradada para %s", aux->reg, aux->name);
			reg = 0;
		}
	}
	unsigned long long int rest = reg % size;
	addIn(&list[rest], reg, name);
	
}

void printHash(Tlist * list, unsigned long long int size){
	int i = 0;
	for(i=0; i<size; i++){
		printf("\n[%d]", i);
		printList(&list[i]);
	}
}

void removeHash(Tlist list[], unsigned long long int size){
	unsigned long long int reg;
	
	printf("\n\n\t=====| REMOVER No |=====\n\n");
	printf("\tInforme MATRICULA a ser REMOVIDA: ");
	scanf("%llu", &reg);

	unsigned long long int rest = reg % size;
	removeIn(&list[rest], reg);
}

unsigned long long int calcSize(FILE* f){
	string s;
	unsigned long long int i=0;
	fseek(f, 0, SEEK_SET);
	while (!feof(f)){
      	fscanf(f, " %[^\n]s", s);
    	i++;
  	}
	fseek(f, 0, SEEK_SET);
	return i;
}

void initializeDB(Tlist list[], FILE* f, unsigned long long int size){
	string name;
	unsigned long long int reg;
	int rest, i=0;

	while (!feof(f)){
      	fscanf(f, " %[^\n]s", name);
		fscanf(f, "%llu", &reg);
		rest = (int) (reg % size);		
		addIn(&list[rest], reg, name);
  	}
}

void saveFile(Tlist list[], unsigned long long int size){
    FILE *file;
    int i;
    Tlist *listPass;
    file = fopen("matriculasTeste.txt", "w");
    for(i = 0; i < size; i++){
        listPass = &list[i];
        Tnode *node = listPass->first; 

        while(node != NULL){
            fprintf(file, "%s\n",  node->name);
            fprintf(file, "%llu\n", node->reg);
            node = node->next;
        }
    }
    fclose(file);
}

void searchStudent(Tlist list[], unsigned long long int size){
	unsigned long long int reg;
	
	printf("\n\n\t=====| PROCURAR No |=====\n\n");
	printf("\tInforme MATRICULA a ser PROCURADA: ");
	scanf("%llu", &reg);

	int rest = (int) (reg % size);
	Tnode *node = searchTnode(list, reg, size);

	if(searchReg(list, reg, size)) {
		printf("\t+-------------------------------------------------+");
		printf("\n\t\tAluno: %s\n\t\tMatricula: %llu\n", node->name, node->reg);
		printf("\t+-------------------------------------------------+");
	}else{
		printf("\t+-------------------------------------------------+");
		printf("\n\t\tMatricula não encontrada");
		printf("\n\t+-------------------------------------------------+");
	}
}
