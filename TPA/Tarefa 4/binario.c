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
void insertTree(TLista *L){
	int reg;

	printf("\nDigite o numero para adicionar: ");
	scanf("%d", &reg);

	L->root = insereNaArvore(&(L->root), reg);
	
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

void printInOrder(TLista *L){
	
	printf("\n============================");
	printf("\n Percurso In Order");
	printf("\n============================\n");

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

TTree* removerArvore(TLista *L, TTree **root, int apagar){
	int resposta = 0;

	if (*root == NULL){
		printf("\nLista Vazia!\n\n");
		return NULL;
	}

	if (apagar < (*root)->valor){
		removerArvore(L, &(*root)->esq, apagar);
	} else if (apagar > (*root)->valor ){
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
                //if (L->root == (*root)) (L->root)=NULL;
            } else if ((*root)->esq == NULL){
                //if (L->root == (*root)) (L->root)=(*root)->dir;
                aux = aux->dir;
                free(aux);
            }else if ((*root)->dir == NULL){
                    //if (L->root == (*root)) (L->root)=(*root)->esq;
                    aux = aux->esq;
                    free(aux);
            }else {
                //if (L->root == (*root)) (L->root)=aux;
                aux = aux->esq;
                while (aux->dir != NULL){
                	aux=aux->dir;
				}
                (*root)->valor = aux->valor;
                aux->valor = apagar;
                
                (*root)->esq = removerArvore(L, root, apagar);
            }
            printf("\n   %s apagado(a) !\n\n", apagar);
        } else {
            printf("\n============================");
            printf("\n%s nao apagado (a)", apagar);
        }
    }
    return (*root);
}

void removeTree(TLista *L){
	int reg;
	TTree *node = L->root;

	printf("\nDigite o numero para apagar: ");
	scanf("%d", &reg);

	L->root = removerArvore(L, &node, reg);
}
