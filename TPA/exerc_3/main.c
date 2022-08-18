/*
=========================================================================================
AUTORES: 	
			Henrique Almeida de Oliveira
			Luiz Eduardo Marchiori
Disciplina: Tópicos de Programação Avançada

Biblioteca de lista Simplesmente encadeada com sentinela
=========================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include"lista.h"
#include"hash.h"

/*
=========================================================================================
			Exemplo usando sentinelaSimples.h
*/

void limparBuffer(){
    char c;
    while((c= getchar()) != '\n' && c != EOF);
}

int menu(){
	int opcao;
	system("@cls||clear"); //Limpa a Tela e posiciona o 
	               //CURSOR no canto esquerdo superior da mesma
    printf("\n\n\n\t     =====| MENU |=====\n\n");
    printf("0 - SAIR (Encerrar Programa).\n\n");
    printf("1 - Adicionar.\n");
    printf("2 - Exibir Lista Completa.\n");
    printf("3 - Remover.\n\n");
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

void main(){	

	int op, i, size;

	FILE *f;
	f = fopen("lista.txt", "a+");  // Cria um arquivo texto para gravação
	if (f == NULL){
		printf("Problemas na Leitura do arquivo\n");
		return;
	}else
	
	printf("\nAberto");

	size = calcSize(f);

	printf("\nTamanho: %s", size);
	limparBuffer();
	char c = getchar();
	
	Tlist tabHash[size], example;
	
	for(i=0; i<size; i++){
		initializeList(&tabHash[i]);
	}
		
	do {
		op = menu();
		
		switch(op){
		   case 1: addElementHash(tabHash, size); break;
		   case 2: printHash(tabHash, size); break;
		   case 3: removeHash(tabHash, size); break;	
		}//switch
		limparBuffer();
		printf("\nPressione qualquer tecla para continuar. . .");
		char c = getchar();
	    system("@cls||clear");
		
	} while(op != 0);
	fclose(f);
	
}
