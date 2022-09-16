#include <stdio.h>
#include <stdlib.h>
#include "binario.h"

void inicializaLista(TLista *L){
	L->root = NULL;
	L->total = 0;
}

TTree *inicializaTree(int add){
	TTree *no = (TTree *)malloc(sizeof(TTree));
    no->valor = add;
	no->esq = NULL;
	no->dir = NULL;
	return no;
}

TTree *insereNaArvore(TTree **node, int add){
	if((*node)==NULL){
		(*node) = inicializaTree(add);
	}else if( (*node)->valor < add ){
		(*node)->dir = insereNaArvore(&(*node)->dir, add);
	}else {
		(*node)->esq = insereNaArvore(&(*node)->esq, add);
	}
	return (*node);
}

// Funcao para inserir um registro
void insereLista(TLista *L){
	int reg;

	printf("\nDigite o número para adicionar: ");
	scanf("%d", &reg);

	insereNaArvore(L->root, reg);
}