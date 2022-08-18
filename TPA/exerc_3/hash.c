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
			Implementacao de hash.h
*/

// adiciona um vetor na tabela hash
void addElementHash (Tlist list[], unsigned long long int tam){
	unsigned long long int  reg;
	string name;
	
	printf("\n\n\n");
	printf("\t=====| INSERE NOVO NO |=====\n\n");
	printf("Informe valor: ");
	scanf("%llu", &reg);
	
	unsigned long long int rest = reg % tam;
	
	printf("\nInforme nome do aluno: ");
	scanf("%s", &name);
	
	addIn(&list[rest], reg, name);
	
}

// imprimir valores na tabela hash
void printHash(Tlist * list, unsigned long long int tam){
	int i = 0;
	for(i=0; i<tam; i++){
		printf("\n[%d]", i);
		printList(&list[i]);
	}
}

// remover valores da tabela hash
void removeHash(Tlist list[], unsigned long long int tam){
	unsigned long long int reg;
	
	printf("\n\n\t=====| REMOVER No |=====\n\n");
	printf("\tInforme VALOR a ser REMOVIDO: ");
	scanf("%llu", &reg);

	unsigned long long int rest = reg % tam;
	removeIn(&list[rest], reg);
}

