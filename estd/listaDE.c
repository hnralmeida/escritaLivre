#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoNo TNo;

typedef char string[40];

typedef struct tipoNo {
	TNo *prox, *ante;
	string nome;
	char sexo;
	float valor;
}TNo;

typedef struct tipoLista {
	int total;
	TNo *inicio;
	TNo *fim;
}TLista;

TLista lista;

void inicializa(TLista *L);
int menu();
void insere(TLista *L);
void exibe(TNo *atual);
void mostraLista(TLista *L);
void mostraListaInversa(TLista *L);
void removerNo(TLista *L);
void automatico(TLista *L);
void reordenarPorNome(TLista *L);
void reordenarPorSexoENome(TLista *L);

int main(){
	int op;
	
	inicializa(&lista);
	
	do {
		op = menu();
		
		switch(op){
		   case 1: insere(&lista); break;
		   case 2: mostraLista(&lista); break;
		   case 3: mostraListaInversa(&lista); break;
		   case 4: removerNo(&lista); break;	
		   case 5: reordenarPorNome(&lista); break;
		   case 6: reordenarPorSexoENome(&lista); break;
		   case 222: automatico(&lista); break;
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
    printf("3 - Exibir Lista Completa Invertida.\n");
    printf("4 - Excluir.\n");
    printf("5 - Reordenar por Nome.\n");
    printf("6 - Reordenar por Nome e Sexo.\n\n");
    printf("\tInforme OPCAO desejada: ");
    
    scanf("%d",&opcao);
    
    if (opcao == 222){
		return opcao;
	}
	
	if ((opcao > 6) || (opcao < 0)){
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
	scanf("%f", &novo->valor);
	limparBuffer();
	printf("Informe o sexo (F ou M): ");
	scanf("%c", &novo->sexo);
	limparBuffer();
	printf("Informe o nome: ");
	scanf(" %[^\n40]s", novo->nome ); 
	
	novo->ante = NULL;
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
   	  
   	  while (atual != NULL){
   	  	if(atual->valor >= novo->valor){
			inserido = 1;
			novo->prox = atual;
			novo->ante = atual->ante;
			
			if(novo->ante == NULL){
				//Inserir novo no in?cio da Lista
				L->inicio = novo;
				atual->ante = novo;
			} else {
				//Inserir novo em algum ponto no meio da Lista
				previo = atual->ante;
				previo->prox = novo;
				
				atual->ante = novo;
			}//if else
			break;
		}//if
		
		atual = atual->prox; //movimenta ponteiro ATUAL para 
		                     //o N? SEGUINTE.
	  }//while
	  
	  if (!inserido){
	     //Inserir novo no final da Lista
		 L->fim->prox = novo;
		 novo->ante = L->fim;
		 L->fim = novo;	
	  }//if
	  
   }//if ... else
   
   L->total++;
}

void addNoLista(TLista *L, float s, char g, string n){
	TNo *novo = (TNo *)malloc(sizeof(TNo));
	int inserido = 0;
	
	novo->valor = s;
	novo->sexo = g;
	strcpy(novo->nome, n);
	
	novo->ante = NULL;
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
   	  
   	  while (atual != NULL){
   	  	if(atual->valor >= novo->valor){
			inserido = 1;
			novo->prox = atual;
			novo->ante = atual->ante;
			
			if(novo->ante == NULL){
				//Inserir novo no in?cio da Lista
				L->inicio = novo;
				atual->ante = novo;
			} else {
				//Inserir novo em algum ponto no meio da Lista
				previo = atual->ante;
				previo->prox = novo;
				
				atual->ante = novo;
			}//if else
			break;
		}//if
		
		atual = atual->prox; //movimenta ponteiro ATUAL para 
		                     //o N? SEGUINTE.
	  }//while
	  
	  if (!inserido){
	     //Inserir novo no final da Lista
		 L->fim->prox = novo;
		 novo->ante = L->fim;
		 L->fim = novo;	
	  }//if
	  
   }//if ... else
   
   L->total++;
}

void automatico(TLista *L){
	
	int i;
	float VSalario[8] = {1720.5, 850.5, 1643.5, 6451.2, 4512.6, 6842.3, 4812.5, 4846.1};
	char VGender[8] = {'M', 'M', 'F', 'M', 'F', 'M', 'M', 'F'};
	string VName[8] = {"Aaron", "Deonhad", "Ester", "Luidevue", "Keboa", "Roebo", "Luca", "Mariella"};
	
	for(i=0; i<8; i++){
		addNoLista(L, VSalario[i], VGender[i], VName[i]);
	}
	L->total = 8;
}

void exibe(TNo *atual){
	printf("\n+-------------------+");
	printf("\n%s\tR$%.2f\n", atual->nome,atual->valor);
}

void mostraLista(TLista *L){
   TNo *atual = L->inicio;
   
   printf("\n\n\n");
   printf("\t=====| EXIBE LISTA COMPLETA |=====\n\n");
   
   while(atual != NULL){
   	   exibe(atual);
   	   atual = atual->prox;
   }//while
   printf("\n\nTotal de Nos: %d\n\n",L->total);
   system("PAUSE");
}

void mostraListaInversa(TLista *L){
   TNo *atual = L->fim;
   
   printf("\n\n\n");
   printf("\t=====| EXIBE LISTA INVERTIDA |=====\n\n");
   
   while(atual != NULL){
   	   exibe(atual);
   	   atual = atual->ante;
   }//while
   printf("\n\nTotal de Nos: %d\n\n",L->total);
   system("PAUSE");
}

void removerNo(TLista *L){
	TNo *atual = L->inicio, *previo = NULL, *proximo = NULL;
	int parametro;
	int removido = 0;
	
	printf("\n\n\t=====| REMOVER No |=====\n\n");
	printf("\tInforme VALOR a ser REMOVIDO: ");
	scanf("%d", &parametro);
	
	while(atual != NULL){
	   if(atual->valor == parametro)	{
	   	  proximo = atual->prox;
	   	  previo = atual->ante;
	   	  
	   	  if(previo == NULL) {
	   	  	  L->inicio = proximo;
	   	  	  if(proximo != NULL) proximo->ante = NULL; 
			  if(atual == L->fim)L->fim = NULL;  
		  } else {
		      previo->prox = proximo;
			  if(proximo != NULL) {
				 proximo->ante = previo;	
			  } else {
			  	 L->fim = previo;
			  }
		  }
		  
		  free(atual);
		  L->total--;
		  removido = 1;
		  break;
	   }//if
	   
	   atual = atual->prox;
	   
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
	strcpy(destino->nome, origem->nome);
	destino->sexo = origem->sexo;
	destino->valor = origem->valor;
}

void reordenarPorNome(TLista *L){
	//Procedimento com o objetivo de reordenar os n?s: ap?s sua execu??o os n?s estar?o em
	//ordem descrescente.
	int i, j;
	if(L->inicio == NULL) return;
	if ( L->total > 1 ) {
		TNo* aux1, * aux2;
		
		for(i=0; i< (L->total); i++){
			aux1 = L->inicio;
			aux2 = aux1->prox;
			j= L->total - i;
			for(j; j>0 ; j--){
				if (strcmp(aux1->nome, aux2->nome)>0){
					TNo* aux;
					aux = (TNo*) malloc(sizeof(struct tipoNo));
					copiarPara(aux, aux2);
					copiarPara(aux2, aux1);
					copiarPara(aux1, aux);
				}
				aux1 = aux2;
				if(aux2->prox!=NULL) aux2 = aux2->prox;
			}
		}
	}	
}

void reordenarPorSexoENome(TLista *L){
	//Procedimento com o objetivo de reordenar os n?s: ap?s sua execu??o os n?s estar?o em
	//ordem descrescente.
	int i, j, fem=0, masc=0;
	
	TNo* aux1, * aux2;
	aux1 = L->inicio;
	for(i=0; i< (L->total); i++){
		if(aux1->sexo == 'F') fem++;
		aux1 = aux1->prox;
	}
	masc = L->total-fem;
	
	if(L->inicio == NULL) return;
	
	if ( L->total > 1 ) {
		for(i=0; i< (L->total); i++){
			aux1 = L->inicio;
			aux2 = aux1->prox;
			j= L->total - i;
			for(j; j>0 ; j--){
				if (aux1->sexo=='M'&&aux2->sexo=='F') {
					TNo* aux;
					aux = (TNo*) malloc(sizeof(struct tipoNo));
					copiarPara(aux, aux2);
					copiarPara(aux2, aux1);
					copiarPara(aux1, aux);
				}
				aux1 = aux2;
				if(aux2->prox!=NULL) aux2 = aux2->prox;
			}
		}
	}	
	
	//dando erro
	if ( L->total > 1 ) {
		for(i=0; i< fem; i++){
			
			if(fem<1) break;
			
			aux1 = L->inicio;
			aux2 = aux1->prox;
			j= fem - i -1;
			for(j; j>0 ; j--){
				if (strcmp(aux2->nome, aux1->nome)<0) {
					TNo* aux;
					aux = (TNo*) malloc(sizeof(struct tipoNo));
					copiarPara(aux, aux2);
					copiarPara(aux2, aux1);
					copiarPara(aux1, aux);
				}
				aux1 = aux2;
				if(aux2->prox!=NULL) aux2 = aux2->prox;
			}
		}
	}
	
	if ( L->total > 1 ) {
		for(i=0; i< masc; i++){
			aux1 = L->inicio;
			
			if(masc<1) break;
			
			while(aux1->sexo!='M') aux1 = aux1->prox;			
			aux2 = aux1->prox;
			
			j= masc - i - 1;
			for(j; j>0 ; j--){
				if (strcmp(aux2->nome, aux1->nome)<0) {
					TNo* aux;
					aux = (TNo*) malloc(sizeof(struct tipoNo));
					copiarPara(aux, aux2);
					copiarPara(aux2, aux1);
					copiarPara(aux1, aux);
				}
				aux1 = aux2;
				if(aux2->prox!=NULL) aux2 = aux2->prox;
			}
		}
	}
}
