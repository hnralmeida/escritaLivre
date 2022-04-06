/*
	HENRIQUE ALMEIDA DE OLIVEIRA

		07-04-2022

		ESTRUTURA DE DADOS - V02 - VANDERSON
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef char string[40];

string vNames[8] = {"Aaron", "Deonhad", "Ervan", "Luidevue", "Keboa", "Roebo", "Luca", "Mariella"};

typedef struct elem {
	struct elem *prox;
	string nome;
	int priv; //prioridade do elemento, de nivel 1 a 3
}elem;

typedef struct fila {
	elem *inicio;
	elem *fim;
	int quant; //quantidade de elementos existentes na fila
	int validador[3];
}fila;

void criarFila(fila *f);

void limparBuffer();

void inserir (fila *f, string nome, int priv);

char* retirarElem (fila *f, string resposta);

void remover(fila *f);

void proximos(fila f);

void exibir (fila f);

void menu(fila *f);

int main(){
	setlocale(LC_ALL, "");
	fila queue;
	criarFila(&queue);

	int nr;
	menu(&queue);

	system("Pause");
	printf("\n");
}

void criarFila(fila *f){
	f -> inicio = NULL;
	f ->fim = NULL;
	f -> quant = 0;
	f->validador[0] = 2;
	f->validador[1] = 1;
	f->validador[2] = 3;
}

void limparBuffer(){
    char c;
    while((c= getchar()) != '\n' && c != EOF);
}

elem* iniciaElem (elem* destino, string nome, int priv){
    elem *novo = (elem*)malloc (sizeof(elem));
	strcpy (novo->nome, nome);
	novo->priv= priv;
	novo -> prox = NULL;
	return novo;
}

void copiaElem (elem* destino, elem* origem){
    strcpy (destino->nome, origem->nome);
	destino->priv = origem->priv;
	destino->prox = (elem*)origem->prox;
}

void inserir (fila *f, string nome, int priv){
	elem *novo = iniciaElem(novo, nome, priv);
	if (f->inicio == NULL) {
		f-> inicio = novo;
		f -> fim = novo;
	} else {
		f->fim->prox = novo;
		f -> fim = novo;
	}
	f->quant++;
}

char* retirarElem (fila *f, string resposta){
	elem *remov = iniciaElem(remov, "", 0);
	copiaElem(remov, f->inicio);
	copiaElem(f->inicio, remov->prox);
	f->quant--;
	if (f->inicio == NULL) f-> fim == NULL;
	strcpy(resposta, remov->nome);
	free(remov);
	return resposta;
}

void remover(fila *f){
	string resposta;
	int prioridade, atend=1;
	prioridade = f->quant>6 ? 6 : f->quant;
	elem *aux = f->inicio;

	if(f-> inicio == NULL){
		printf("\nFila Vazia");
	} else {
	    while(prioridade){
	        if(aux->priv==atend){
                prioridade = 0;
	        }else{
                aux = aux->prox;
                prioridade--;
	        }
	        if(prioridade==1){
                atend++;
                aux = f->inicio;
            }
	    }
	    if(f->inicio->prox!=NULL){
            elem* troca = iniciaElem(troca, "", 0);
            copiaElem(troca, aux);
            copiaElem(aux, f->inicio);
            copiaElem(f->inicio, troca);
            printf("Trocar %s por %s", aux->nome, troca->nome);
	    }else{
	        elem* troca = iniciaElem(troca, "", 0);
            copiaElem(troca, aux);
            f->inicio = NULL;
            f->fim = NULL;
            free(aux);
	    }

        if (aux->priv == 3 ){
            if(f->validador[0] > 0 ) {
                strcpy(resposta, retirarElem(f, resposta));
                f->validador[2]--;
            }
        }else if(aux->priv == 2){
            if(!f->validador[1]){
                if ( !f->validador [2]) f->validador[2] = 3;
                f->validador[1] = 1;
            }
            strcpy(resposta, retirarElem(f, resposta));
            f->validador[1]--;
        }else if(aux->priv == 1){
            if(!f->validador[0]){
                if ( !f->validador [2]) f->validador[2] = 3;
                f->validador[0] = 2;
            }
            strcpy(resposta, retirarElem(f, resposta));
            f->validador[0]--;
        }
	}
	printf("\n%s Removido", resposta);
}

void proximos(fila f){
	int top, atend=f.quant;
	top = f.quant>6 ? 6 : f.quant;
	elem *aux = f.inicio;


    while(atend&&top){
        if (aux->priv==1){
            printf("Nome: %s, Prioridade: %d\n", aux->nome, aux->priv);
            top--;
        }
        aux = aux->prox;
        atend--;
    }
    aux = f.inicio;
    atend=f.quant;
    while(atend&&top){
        if (aux->priv==2){
            printf("Nome: %s, Prioridade: %d\n", aux->nome, aux->priv);
            top--;
        }
        aux = aux->prox;
        atend--;
    }
    aux = f.inicio;
    atend=f.quant;
    while(atend&&top){
        if (aux->priv==3){
            printf("Nome: %s, Prioridade: %d\n", aux->nome, aux->priv);
            top--;
        }
        aux = aux->prox;
        atend--;
    }
}

void exibir (fila f){
	elem* aux;
	aux = f.inicio;
	int i, q = f.quant;

	for (i=0; i<q;i++){
		if (aux->priv==1)
			printf("Nome: %s, Prioridade: %d\n", aux->nome, aux->priv);
		aux = aux->prox;
	}
	aux = f.inicio;
	i=0;
	for (i=0; i<q;i++){
		if (aux->priv==2)
			printf("Nome: %s, Prioridade: %d\n", aux->nome, aux->priv);
		aux = aux->prox;
	}
	aux = f.inicio;
	i=0;
	for (i=0; i<q;i++){
		if (aux->priv==3)
			printf("Nome: %s, Prioridade: %d\n", aux->nome, aux->priv);
		aux = aux->prox;
	}
}

void menu(fila *f){

	int number, priv, loop =1;
	string nome;

	while(loop){
		printf("\n_____________________________\nSelecione uma opcao");
		printf("\n_____________________________");
		printf("\n0- Sair\n1- Inserir na fila\n2- Remover");
		printf("\n3- Exibir\n4- Exibir 6 Proximos\n5- Iniciar Exemplo");
		printf("\n_____________________________\nEntrada: ");
		scanf("%d", &number);

		switch(number){
            case 0:
                printf("Saindo do Programa\n\n");
                exit(0);

            case 1:
            	printf("Digite um nome: ");
            	scanf(" %40[^\n]s", nome);
            	do{
            	printf("Coloque a prioridade (1 a 3) de %s: ", nome);
            	scanf("%d", &priv);
				}while(priv < 0 || priv > 3);

            	inserir(f, nome, priv);

                break;


            case 2:
            	remover(f);
                break;

            case 3:
                exibir (*f);
                break;

            case 4:
                proximos(*f);
                break;

            case 5:
                inserir(f, vNames[0], 3);
            	inserir(f, vNames[1], 2);
            	inserir(f, vNames[2], 1);
            	inserir(f, vNames[3], 3);
            	inserir(f, vNames[4], 2);
            	inserir(f, vNames[5], 1);
            	inserir(f, vNames[6], 1);
            	inserir(f, vNames[7], 1);
            	break;

            default:
                printf("\nNão é uma opção válida");
   				break;
        }
        printf("\n\nPressione Enter Para Sair...");
        limparBuffer();
        char c = getchar();

        system("@cls||clear");
	}
}
