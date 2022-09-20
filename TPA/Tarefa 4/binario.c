/*
=========================================================================================
AUTORES: 	
			Henrique Almeida de Oliveira
			Luiz Eduardo Marchiori
Disciplina: TÃ³picos de ProgramaÃ§Ã£o AvanÃ§ada

ImplementaÃ§Ã£o da biblioteca BINARIO
=========================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "binario.h"
/*
=========================================================================================
			ImplementaÃ§Ã£o
*/

TTree *digThrowTree(TTree* node, int v); //funcao de busca

void initializeSentinel(TSentinel *L){
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
void insertTree(TSentinel *L){
	int reg;
	TTree* valid;

	printf("\nDigite o numero para adicionar: ");
	scanf("%d", &reg);

	valid = digThrowTree(L->root, reg);

	if (valid->valor =! reg) L->root = insereNaArvore(&(L->root), reg);
	else printf("Valor ja existe na arvore");
	
}

void printDepth(TTree* node){
	if(node==NULL) return; 	 
	printf("- %d ", node->valor);
	printDepth(node->esq);
	printDepth(node->dir);
}

void printDepthFirst(TSentinel *L){
	
	printf("\n============================");
	printf("\n Percurso em Pre-Ordem");
	printf("\n============================\n");

	TTree* node = L->root;
	printDepth(node);
}

void printIn(TTree* node){
	if(node==NULL) return; 	 
	printDepth(node->esq);
	printf("- %d ", node->valor);
	printDepth(node->dir);
}

void printInOrder(TSentinel *L){
	
	printf("\n================================================\n");
	printf("\n Percurso In Order");
	printf("\n================================================\n\n");

	TTree* node = L->root;
	printIn(node);
	printf("\n\n================================================\n\n");
}

void printPos(TTree* node){
	if(node==NULL) return; 	 
	printDepth(node->esq);
	printDepth(node->dir);
	printf("- %d ", node->valor);
}

void printPosOrder(TSentinel *L){
	
	printf("\n============================");
	printf("\n Percurso Pos Order");
	printf("\n============================\n");

	TTree* node = L->root;
	printPos(node);
}

//subfuncao de removerGeral utilizada para pegar o nÃ³ mais a direita da subarvore esquerda do nÃ³ que serÃ¡ removido
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

// subfuncao de removeTree
TTree* removerArvore(TSentinel *L, TTree **raiz, int apagar){
	int resposta = 0;
	if (*raiz == NULL){
		printf("\nNome não encontrado!\n\n");
		return NULL;
	}

	if (apagar < (*raiz)->valor){
		removerArvore(L, &(*raiz)->esq, apagar);
	} else if (apagar > (*raiz)->valor){
        removerArvore(L, &(*raiz)->dir, apagar);
    } else {
        printf("\n============================");
        printf("\n   Apagar %d?\n   1 - Sim\n   0 - Nao\n\n-> ", (*raiz)->valor);
        scanf("%i", &resposta);
        printf("\n============================");

        if (resposta){
            TTree *aux = (*raiz);
            if (((*raiz)->esq == NULL) && ((*raiz)->dir == NULL)){
                (*raiz) = NULL;
                free(aux);
            } else if ((*raiz)->esq == NULL){
				printf("esq == NULL");
                (*raiz) = (*raiz)->dir;
                free(aux);
            }else if ((*raiz)->dir == NULL){
				printf("dir == NULL");
				(*raiz) = (*raiz)->esq;
                free(aux);
            }else {
				printf("else");
                (*raiz) = raizDireita(raiz);
                free(aux);
            }
            printf("\nNumero %d apagado(a) !\n\n", apagar);
        } else {
            printf("\n============================");
            printf("\nNumero %d não apagado (a)", apagar);
        }
    }
	return *raiz;
}

void removeTree(TSentinel *L){
	int reg;
	TTree *node = L->root;

	printf("\nDigite o numero para apagar: ");
	scanf("%d", &reg);

	L->root = removerArvore(L, &node, reg);
}

// Subfunção de procuraValor, recursiva, retorna struct tree encontrada
TTree *digThrowTree(TTree* node, int v){
	TTree *x;

	if(node!=NULL) x = node;

	if (node==NULL){
		return NULL;
	}else if(x->valor = v){
		return x;
	}else if(x->valor>v){
		digThrowTree(node->esq, v);
	}else{
		digThrowTree(node->dir, v);
	}
}

void searchValue(TSentinel *L){

	TTree *aux = L->root;
	int valor;

	if(aux == NULL){
		printf("\nArvore Vazia!");
	}else{
		printf("\nQual valor deseja procurar?\n> ");
		scanf("%d", &valor);
		TTree *x = digThrowTree(aux, valor);

		if (x==NULL){
			printf("\nNão encontrado!");
		}else{
			printf("\nEncontrado!");
			printf("\n%d", x->valor);
		}
	}
}

void automatico(TSentinel *L){
	L->root = insereNaArvore(&(L->root), 12);
	L->root = insereNaArvore(&(L->root), 5);
	L->root = insereNaArvore(&(L->root), 1);
	L->root = insereNaArvore(&(L->root), 2);
	L->root = insereNaArvore(&(L->root), 15);
	L->root = insereNaArvore(&(L->root), 25);
}