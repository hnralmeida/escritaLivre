#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef char string[40];

typedef struct tipoNo TNo;

typedef struct tipoNo {
	TNo *prox;
	string nome;
	char sexo;
	float salario;	
}TNo;

typedef struct tipoLista TLista;

typedef struct tipoLista {
	int total;
	TNo *inicio;
	TNo *fim;
}TLista;

void inicializa(TLista *L);
int menu();
void insere(TLista *L);
void exibe(TNo *atual);
void mostraLista(TLista *L);
void remover(TLista *L);
void reordenarSalario(TLista *L, int ini, int fim );

int main(){
	
	setlocale(LC_ALL, "");
	
	int op;
	
	TLista lista;
	
	inicializa(&lista);
	
	do {
		op = menu();
		
		switch(op){
		   case 1: insere(&lista); break;
		   case 2: mostraLista(&lista); break;
		   case 3: remover(&lista); break;	
		}//switch
		
	} while(op != 0);
	
}

void inicializa(TLista *L){
	L->inicio = NULL;
	L->fim = NULL;
	L->total = 0;
}

int menu(){
	int opcao;
	system("CLS"); //Limpa a Tela e posiciona o 
	               //CURSOR no canto esquerdo superior da mesma
    printf("\n\n\n\t     =====| MENU |=====\n\n");
    printf("0 - SAIR (Encerrar Programa).\n\n");
    printf("1 - Inserir.\n");
    printf("2 - Exibir Lista Completa.\n");
    printf("3 - Excluir.\n\n");
    printf("\tInforme OPCAO desejada: ");
    
    scanf("%d",&opcao);
	
	if ((opcao > 3) || (opcao < 0)){
		printf("\n\n\n");
		printf("\t+-------------------------------------------------+");
		printf("\t|   ERRO:                                         |");
		printf("\t|                                                 |");
		printf("\t|   OPCAO INVALIDA!!!                             |");
		printf("\t|                                                 |");
		printf("\t|   Tente outra vez.                              |");
		printf("\t+-------------------------------------------------+\n\n");
		system("PAUSE");
	}
	return opcao;
}

void limparBuffer(){
    char c;
    while((c= getchar()) != '\n' && c != EOF);
}

void insere(TLista *L){
   TNo *novo = (TNo *)malloc(sizeof(TNo));
   int inserido = 0;
   string nome;
   char sexo;
   
   printf("\n\n\n");
   printf("\t=====| INSERE NOVO NO |=====\n\n");
   printf("Informe salário: ");
   scanf("%f", &novo->salario);
   limparBuffer();
   printf("Informe o sexo (F ou M): ");
   scanf("%c", &novo->sexo);
   limparBuffer();
   printf("Informe o nome: ");
   scanf(" %[^\n40]s", novo->nome ); 
   
   
   novo->prox = NULL;
   
   if(L->inicio == NULL){
   	  //Lista VAZIA: inserir o primeiro N?.
   	  L->inicio = novo;
   	  L->fim = novo;
   } else {
   	  //Lista possui pelo menos um N?: Inserir dados em
   	  //ordem crescente.
   	  TNo *atual = L->inicio;
   	  TNo *previo = NULL;
   	  
   	  //Inserir novo no final da Lista
	 L->fim->prox = novo;
	 L->fim = novo;	
   }//if ... else
   
   L->total++;
}

void exibe(TNo *atual){
	printf("\n+-------------------+");
	printf("\n%s\tR$%.2f\n", atual->nome,atual->salario);
}

void mostraLista(TLista *L){
   TNo *atual = L->inicio;
   
   printf("\n\n\n");
   printf("\t=====| EXIBE LISTA COMPLETA |=====\n\n");
   
   while(atual != NULL){
   	   exibe(atual);
   	   atual = atual->prox;
   }//while
   printf("\n\n");
   system("PAUSE");
}

void remover(TLista *L){
	TNo *atual = L->inicio, *previo = NULL, *proximo;
	string parametro;
	
	int removido = 0;
	
	if(L->inicio == NULL) proximo = NULL;
	else proximo = atual->prox;
	
	printf("\n\n\t=====| REMOVER No |=====\n\n");
	printf("\tInforme VALOR a ser REMOVIDO: ");
	scanf("%s", &parametro);
	
	while(atual != NULL){
	   if(!strcmp(atual->nome, parametro)){
	   	  proximo = atual->prox;
	   	  if(previo == NULL) L->inicio = proximo;
	   	  else previo->prox = proximo;
		  free(atual);
		  L->total--;
		  removido = 1;
		  break;
	   }//if
	   previo = atual;
	   atual = atual->prox;
	   if(atual != NULL) proximo = atual->prox;
	   else proximo = NULL;
	}//while
	
	if(removido){
		printf("\n\n\n");
		printf("+--------------------------------------+\n");
		printf("|  AVISO:                              |\n");
		printf("|                                      |\n");
		printf("|  No REMOVIDO com SUCESSO !!!         |\n");
		printf("|                                      |\n");
		printf("+--------------------------------------+\n\n\n");
		system("PAUSE");
	} else {
		printf("\n\n\n");
		printf("+--------------------------------------+\n");
		printf("|  ALERTA:                             |\n");
		printf("|                                      |\n");
		printf("|  No NAO ENCONTRADO e nem REMOVIDO!!! |\n");
		printf("|                                      |\n");
		printf("+--------------------------------------+\n\n\n");
		system("PAUSE");		
	}
}

void copiarPara(TNo* destino, TNo* origem){
    destino->prox = origem->prox;
	strcpy(destino->nome, origem->nome);
	destino->sexo = origem->sexo;
	destino->salario = origem->salario;	  
}

int particao(TNo *L, int ini, int fim) {
	int i, f;
	TNo* aux, * pivo;
	aux = (TNo*) malloc(sizeof(struct tipoNo));
	pivo = (TNo*) malloc(sizeof(struct tipoNo));

	if (ini < fim) {
        copiarPara(pivo, L->inicio);
        copiarPara(aux, L->fim);
        i = ini+1;
        f = fim-1;

        if ( strcmp(pivo->usuario.nome, aux->usuario.nome)<0 ){
            copiarPara(L->, pivo);
            copiarPara(&banco[fim], aux);
            particao(banco,i,fim);
        }
        return particao(banco,ini,f);
	}

}

void reordenarSalario(TLista *L){
	//Procedimento com o objetivo de reordenar os n?s: ap?s sua execu??o os n?s estar?o em
	//ordem descrescente.
	int i, tamAux;
	
	if ( L->total ) {
		TLista* aux1, * aux2;
		aux1 = (TLista*) malloc(sizeof(struct tipoLista));
		aux2 = (TLista*) malloc(sizeof(struct tipoLista));
		
		aux1->inicio = L->inicio;
		for(i=0; i< ((L->total)/2); i++) aux1->fim = aux1->fim->prox;
		aux1->total = L->total/2;
		
		aux2->inicio = aux1->fim->prox;
		aux2->fim = L->fim;
		aux2->total = (aux1->total)/2;
		
		reordenarSalario(aux1);
		reordenarSalario(aux2);
	}
}
