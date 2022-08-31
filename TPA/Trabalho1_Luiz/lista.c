// -- Luiz Eduardo Marchiori --

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

// inicializa lista com ponteiros nulos
void inicializarlista(Tlista *lista){
	lista->primeiro=NULL;
	lista->ultimo=NULL;
	lista->total=0;
}

void adicionarEm(Tlista * lista, unsigned long long int  registro, string nome){

	TNo *novoNo = (TNo *)malloc(sizeof(TNo));
	int flag=1;
	novoNo->registro = registro;
	novoNo->proximo = NULL;
	strcpy(novoNo->nome, nome);	
	if(lista->primeiro == NULL){
		lista->primeiro = novoNo;
		lista->ultimo = novoNo;
	} else {
		TNo *atual = lista->primeiro;
		TNo *anterior = NULL;
		
		while(atual != NULL && (novoNo->registro >= atual->registro) ){
			anterior = atual;
			atual = atual->proximo;
		}	
		
		if (atual == NULL && (anterior!= lista->primeiro) ){
			anterior->proximo = novoNo;
			lista->ultimo = novoNo;
		}else if (atual == lista->primeiro){
			novoNo->proximo = atual; 
			lista->primeiro = novoNo;
		}else{
			novoNo->proximo = atual;
			anterior->proximo = novoNo;
		}


	}
	
	lista->total++;
}

void adicionarElemento(Tlista *lista){
	unsigned long long int registro;
	string nome;
		
	printf("\n\n\n");
	printf("\t=====| INSERE |=====\n\n");
	printf("Informe a matrícula: ");
	scanf("%llu", &registro);

	printf("\nInforme o nome do aluno: ");
	scanf("%s", &nome);
	
	adicionarEm(lista, registro, nome);
}

void printlista(Tlista *lista){
	int i=0;
	TNo *celula = lista->primeiro;
	
	if(celula == NULL) {
		printf("-");
	}
	
	while (celula!=NULL){
		printf(" -> %llu", celula->registro);
		celula = celula->proximo;
	}
}

void removerEm(Tlista * lista, unsigned long long int registro){

	TNo *atual = lista->primeiro, *anterior = NULL;
	string nome_removido;
	unsigned long long int registro_removido;
	int removido = 0;

	if(atual == NULL)
		printf("\nLista vazia...");
	else{
		while(atual != NULL && (atual->registro != registro)){
			anterior = atual;
			atual = atual->proximo;
		}

		if(atual!=NULL){
			strcpy(nome_removido, atual->nome);
			registro_removido = atual->registro;
			removido = 1;
			lista->total--;
		}
		else {
			printf("Essa matrícula nao existe");
			return;
		}
		
		if(atual->proximo == lista->ultimo){ 
			anterior->proximo = NULL;
			lista->ultimo = anterior;
			free(atual);
		}else if(anterior == NULL){
			anterior = atual->proximo;
			lista->primeiro = anterior;
			free(atual);
		}else {
			anterior->proximo = atual->proximo;
			free(atual);
		}
	}
	
	if(removido){
		printf("\n\n\n");
		printf("+--------------------------------------+\n");
		printf("\n\t%s\n", nome_removido);
		printf("\t%llu\n", registro_removido);
		printf("\n\tREMOVIDO com SUCESSO !!!\t\n");
		printf("+--------------------------------------+\n\n\n");
		
	} else {
		printf("\n\n\n");
		printf("+--------------------------------------+\n");
		printf("|  ALERTA:                             |\n");
		printf("|                                      |\n");
		printf("|  Matrícula não encontrada e nem removida!!! |\n");
		printf("|                                      |\n");
		printf("+--------------------------------------+\n\n\n");

	}
}

void removerElemento(Tlista *lista){

	unsigned long long int registro;
	
	printf("\n\n\t=====| REMOVER |=====\n\n");
	printf("\tInforme a matrícula a ser removida: ");
	scanf("%llu", &registro);

	removerEm(lista, registro);
}
