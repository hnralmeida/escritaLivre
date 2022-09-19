/*
=========================================================================================
AUTORES: 	
			Henrique Almeida de Oliveira
			Luiz Eduardo Marchiori
Disciplina: Tópicos de Programação Avançada

Implementação da biblioteca BINARIO
=========================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "binario.h"
/*
=========================================================================================
			Implementação
*/

void initializeTree(TLista *L){
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

TTree *insereNaArvore(TTree *node, int add){
	if((node)==NULL){
		(node) = inicializaTree(add);
	}else if( (node)->valor < add ){
		(node)->dir = insereNaArvore((node)->dir, add);
	}else {
		(node)->esq = insereNaArvore((node)->esq, add);
	}
	return (node);
}

// Funcao para inserir um registro
void insertTree(TLista *L){
	int reg;
	TTree *node = L->root;

	printf("\nDigite o numero para adicionar: ");
	scanf("%d", &reg);

	node = insereNaArvore(node, reg);
}

void printDepth(TTree* node){
	if(node==NULL) return; 	 
	printf("- %d ", node->valor);
	printDepth(node->esq);
	printDepth(node->dir);
}

void printDepthFirst(TLista *L){
	
	printf("\n============================");
	printf("\n Percurso em Pre-Ordem");
	printf("\n============================");

	TTree* node = L->root;
	printDepth(node);
}

void printIn(TTree* node){
	if(node==NULL) return; 	 
	printDepth(node->esq);
	printf("- %d ", node->valor);
	printDepth(node->dir);
}

void printInOrder(TLista *L){
	
	printf("\n============================");
	printf("\n Percurso In Order");
	printf("\n============================");

	TTree* node = L->root;
	printIn(node);
}

void printPos(TTree* node){
	if(node==NULL) return; 	 
	printDepth(node->esq);
	printDepth(node->dir);
	printf("- %d ", node->valor);
}

void printPosOrder(TLista *L){
	
	printf("\n============================");
	printf("\n Percurso Pos Order");
	printf("\n============================");

	TTree* node = L->root;
	printPos(node);
}

//subfuncao de removerGeral utilizada para pegar o nó mais a direita da subarvore esquerda do nó que será removido
TTree *raizDireita(TTree **no){
	if ((*no)->dir != NULL){
		return raizDireita(&(*no)->dir);
	} else {
		TTree *aux1 = *no;
		if ((*no)->esq != NULL)
			*no = (*no)->esq;
		else
			*no = NULL;
	return aux1;
	}
}

void removerArvore(TLista *L, TTree **root, int apagar){
	int resposta = 0;

	if (*root == NULL){
		printf("\nLista Vazia!\n\n");
		return;
	}

	if (apagar == (*root)->valor){
		removerArvore(L, &(*root)->esq, apagar);
	} else if (apagar == (*root)->valor ){
        removerArvore(L, &(*root)->dir, apagar);
    } else {
        printf("\n============================");
        printf("\n   Apagar %d?\n   1 - Sim\n   0 - Nao\n\n-> ", (*root)->valor);
        scanf("%i", &resposta);
        printf("\n============================");
        if (resposta){
            TTree *aux = (*root);
            if (((*root)->esq == NULL) && ((*root)->dir == NULL)){
                free(aux);
                (*root) = NULL;
                if (L->root == (*root)) (L->root)=NULL;
            } else if ((*root)->esq == NULL){
                if (L->root == (*root)) (L->root)=(*root)->dir;
                (*root) = (*root)->dir;
                aux->dir = NULL;
                free(aux);
                aux = NULL;
            }else if ((*root)->dir == NULL){
                    if (L->root == (*root)) (L->root)=(*root)->esq;
                    (*root) = (*root)->esq;
                    aux->esq = NULL;
                    free(aux);
                    aux = NULL;
            }else {
                if (L->root == (*root)) (L->root)=aux;
                aux = raizDireita(&(*root)->esq);
                aux->esq = (*root)->esq;
                aux->dir = (*root)->dir;
                free((*root));
                (*root) = aux;
            }
            printf("\n   %s apagado(a) !\n\n", apagar);
        } else {
            printf("\n============================");
            printf("\n%s não apagado (a)", apagar);
        }
    }
}

void removeTree(TLista *L){
	int reg;
	TTree *node = L->root;

	printf("\nDigite o numero para apagar: ");
	scanf("%d", &reg);

	removerArvore(L, &node, reg);
}