#include <stdio.h>
#include <stdlib.h>

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
}fila;

void criarFila(fila *f){
	f -> inicio = NULL;
	f ->fim = NULL;
	f -> quant = 0;
}

void inserir (fila *f, int numero, string nome, int priv){
	elem *novo = (elem*)malloc (sizeof(elem));
	strcpy (novo->nome, nome);
	novo->priv= priv; 
	novo -> info = numero;
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

int remover(fila *f){
	string resposta;
	
	if(f-> inicio == NULL){
		return 0;
	} else {
		elem *atual= f->inicio;
		f->inicio= atual -> prox;
		if (f->inicio == NULL) f-> fim == NULL;
		strcpy(resposta, atual->nome);
		free(atual);
		return resposta;
	}
}
void exibir (f){
	int i;
		for (i=0; i<quant;i++){
			if (f->elem->priv==1){
			printf("Nome: %s, Prioridade: %d\n", f.elem[i].nome, f.elem[i].priv);
		} 
	}
		for (i=0; i<quant;i++){
			if (f->elem->priv==2){
				printf("Nome: %s, Prioridade: %d\n", f->elem[i]->nome, f->elem[i]->priv);
		} 
	}
		for (i=0; i<quant;i++){
			if (f->elem->priv==3){
				printf("Nome: %s, Prioridade: %d\n", f->elem[i]->nome, f->elem[i]->priv);
		} 
	}
}

void menu(fila *f){

	int number, loop =1;
	string nome;

	while(loop){
		printf("\n_____________________________\nSelecione uma opção");
		printf("\n_____________________________");
		printf("\n0- Sair\n1- Inserir na fila\n2- Imprimir amigos de ...");
		printf("\n3- Usuários mais populares\n4- Usuários menos populares");
		printf("\n5- Sugestões de amizades");
		printf("\n_____________________________\nEntrada: ");
		scanf("%d", &number);

		switch(number){
            case 0:
                printf("Saindo do Programa");
                loop = 0;
                return;

            case 1:
            	string nome;
            	int priv;
            	printf("Digite um nome: ");
            	scanf(" %40[^\n]s, nome");
            	do{
            	printf("Coloque a prioridade (1 a 3) de: %s", nome);
            	scanf("%d", priv);}while priv < 0 || priv > 3;
            	inserir(f,numero, nome, priv);
                break;
                

            case 2:
                break;

            case 3:
                exibir (f);
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
	fila queue;
	criarFila(&queue);
	
	int nr;
	do {
		nr=remover(&queue);
		printf("\n\nRemovido: %d", nr);
		
	}while (nr != 0);
	system("Pause");
	printf("\n");
}


