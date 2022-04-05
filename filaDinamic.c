#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef char string[40];

typedef struct elem {
	struct elem *prox;
	string nome;
	int priv; //prioridade do elemento, de nivel 1 a 3
}elem;

typedef struct fila {
	struct elem *inicio;
	struct elem *fim;
	int quant; //quantidade de elementos existentes na fila
	int validador[3];
}fila;

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

void inserir (fila *f, int numero, string nome, int priv){
	elem *novo = (elem*)malloc (sizeof(elem));
	strcpy (novo->nome, nome);
	novo->priv= priv; 
	novo -> prox = NULL;
	if (f->inicio == NULL) {
		f-> inicio = novo;
		f -> fim = novo;
	} else {
		f->fim->prox = novo;
		f -> fim = novo;
	}
	f->quant++;
}

/*string removerMesmo (fila *f){
	string resposta;
	elem *remov = f->inicio;
	f->inicio = remov -> prox;
	if (f->inicio == NULL) f-> fim == NULL;
	strcpy(resposta, remov->nome);
	free(atual);
	return resposta;
}*/

int remover(fila *f){
	string resposta;
	
	if(f-> inicio == NULL){
		printf("\nNull?");
		return 0;
	} else {
		printf("\nEntrando no if...");
		if (f->inicio->priv == 3 ){
			if(f->validador[0] > 0 ) {
				string resposta;
				elem *remov = f->inicio;
				f->inicio = remov -> prox;
				if (f->inicio == NULL) f-> fim == NULL;
				strcpy(resposta, remov->nome);
				free(remov);
				f->validador[2]--;
			}
		}else if(f->inicio->priv == 2){
			if(!f->validador[1]){
				if ( !f->validador [2]) f->validador[2] = 3;
				f->validador[1] = 1;
			}
			string resposta;
			elem *remov = f->inicio;
			f->inicio = remov -> prox;
			if (f->inicio == NULL) f-> fim == NULL;
			strcpy(resposta, remov->nome);
			free(remov);
			f->validador[1]--;
		}else if(f->inicio->priv == 1){
			if(!f->validador[0]){
				if ( !f->validador [2]) f->validador[2] = 3;
				f->validador[0] = 2;
			}
			printf("\nRemovendo...");
			string resposta;
			elem *remov = f->inicio;
			f->inicio = remov -> prox;
			if (f->inicio == NULL) f-> fim == NULL;
			strcpy(resposta, remov->nome);
			free(remov);
			f->validador[0]--;
		}
	}
	printf("\n%s Removido", resposta);
	return 1;
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
		printf("\n_____________________________\nSelecione uma opção");
		printf("\n_____________________________");
		printf("\n0- Sair\n1- Inserir na fila\n2- Remover");
		printf("\n3- Exibir\n4- Exibir 6 Próximos");
		printf("\n_____________________________\nEntrada: ");
		scanf("%d", &number);

		switch(number){
            case 0:
                printf("Saindo do Programa");
                loop = 0;
                return;

            case 1:
            	printf("Digite um nome: ");
            	scanf(" %40[^\n]s", nome);
            	do{
            	printf("Coloque a prioridade (1 a 3) de %s: ", nome);
            	scanf("%d", &priv);
				}while(priv < 0 || priv > 3);
				
            	inserir(f, number, nome, priv);
                break;
                

            case 2:
            	remover(f);
                break;

            case 3:
                exibir (*f);
                break;

            case 4:
                break;

            case 5:
   				break;
        }
        printf("\n\nPressione Enter Para Sair...");
        limparBuffer();
        char c = getchar();

        system("@cls||clear");
	}
}

int main(){
	setlocale(LC_ALL, "");
	fila queue;
	criarFila(&queue);
	
	int nr;
	menu(&queue);
	
	system("Pause");
	printf("\n");
}

