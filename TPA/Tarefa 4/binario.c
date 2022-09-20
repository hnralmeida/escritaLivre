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

void initializeTree(TTree* no, int add){
    no->value = add;
	no->esq = NULL;
	no->dir = NULL;
}


void insereNaArvore(TTree **node, TTree* insert){
	if((*node)==NULL){
		(*node) = insert;
	}else if( insert->value > (*node)->value ){
		insereNaArvore(&(*node)->dir, insert);
	}else {
		insereNaArvore(&(*node)->esq, insert);
	}
}

// Funcao para inserir um registro
void insertTree(TSentinel *L){
	int reg;
	TTree* valid;

	printf("\nDigite o numero para adicionar: ");
	scanf("%d", &reg);

	valid = digThrowTree(L->root, reg);
	TTree *no = (TTree *)malloc(sizeof(TTree));
    initializeTree(no, reg);

	if (valid->value =! reg) insereNaArvore(&(L->root), no);
	else printf("Valor ja existe na arvore");
	
}

void printDepth(TTree* node){
	if(node==NULL) return; 	 
	printf("- %d ", node->value);
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
	printf("- %d ", node->value);
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
	printf("- %d ", node->value);
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
		TTree *aux = (*no);
		if ((*no)->esq != NULL)
			*no = (*no)->esq;
		else
			(*no) = NULL;
	return aux;
	}
}

// subfuncao de removeTree
TTree* removerArvore(TSentinel *L, TTree **raiz, int apagar){
	int resposta = 0;
	if (*raiz == NULL){
		printf("\nNome não encontrado!\n\n");
		return NULL;
	}

	if (apagar < (*raiz)->value){
		removerArvore(L, &(*raiz)->esq, apagar);
	} else if (apagar > (*raiz)->value){
        removerArvore(L, &(*raiz)->dir, apagar);
    } else {
        printf("\n============================");
        printf("\n   Apagar %d?\n   1 - Sim\n   0 - Nao\n\n-> ", (*raiz)->value);
        scanf("%i", &resposta);
        printf("\n============================");

        if (resposta){
            TTree *aux = (*raiz);
            if (((*raiz)->esq == NULL) && ((*raiz)->dir == NULL)){
                (*raiz) = NULL;
            } else if ((*raiz)->esq == NULL){
				printf("esq == NULL");
                (*raiz) = (*raiz)->dir;
            }else if ((*raiz)->dir == NULL){
				printf("dir == NULL");
				(*raiz) = (*raiz)->esq;
            }else {
				printf("else");
				TTree *copy = (*raiz);
                (*raiz) = raizDireita(&(*raiz)->esq);
				(*raiz)->dir = copy->dir;
				(*raiz)->esq = copy->esq;
            }
            printf("\nNumero %d apagado(a) !\n\n", aux->value);
			free(aux);
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
	}else if(x->value = v){
		return x;
	}else if(x->value>v){
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
			printf("\n%d", x->value);
		}
	}
}

void insereAuto(TTree **root, int reg){
	
	TTree *no = (TTree *)malloc(sizeof(TTree));
    initializeTree(no, reg);

	insereNaArvore(root, no);
}

void automatico(TSentinel *L){
	insereAuto(&(L->root), 12);
	insereAuto(&(L->root), 5);
	insereAuto(&(L->root), 1);
	insereAuto(&(L->root), 2);
	insereAuto(&(L->root), 15);
	insereAuto(&(L->root), 25);
}