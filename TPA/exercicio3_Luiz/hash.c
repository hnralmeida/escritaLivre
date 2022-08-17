// -- Luiz Eduardo Marchiori -- 


#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "lista.h"

void adicionarHash (Tlista lista[], unsigned long long int tam){
	unsigned long long int  registro;
	string nome;
	
	printf("\n\n\n");
	printf("\t=====| INSERE NOVO |=====\n\n");
	printf("Informe o nº da matrícula: ");
	scanf("%llu", &registro);
	
	unsigned long long int rest = registro % tam;
	
	printf("\nInforme o nome do aluno: ");
	scanf("%s", &nome);
	
	adicionarEm(&lista[rest], registro, nome);
	
}

void printHash(Tlista * lista, unsigned long long int tam){
	int i = 0;
	for(i=0; i<tam; i++){
		printf("\n[%d]", i);
		printlista(&lista[i]);
	}
}

removerHash(Tlista lista[], unsigned long long int tam){
	unsigned long long int registro;
	
	printf("\n\n\t=====| REMOVER |=====\n\n");
	printf("\tInforme a matrícula a ser removida: ");
	scanf("%llu", &registro);

	unsigned long long int rest = registro % tam;
	removerEm(lista[rest], registro);
}

