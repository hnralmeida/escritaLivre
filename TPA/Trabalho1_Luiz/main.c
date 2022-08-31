// -- Luiz Eduardo Marchiori --

#include<stdio.h>
#include<stdlib.h>
#include"lista.h"
#define TAM 5

void limparBuffer(){
    char c;
    while((c= getchar()) != '\n' && c != EOF);
}

int menu(){
	int opcao;
	system("@cls||clear");
    printf("\n\n\n\t     =====| MENU |=====\n\n");
    printf("0 - SAIR (Encerrar Programa).\n\n");
    printf("1 - Adicionar.\n");
    printf("2 - Exibir lista Completa.\n");
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
		printf("\t+-------------------------------------------------+\n\n");
		system("PAUSE");
	}
	return opcao;
}

void main(){	

	int op, i;
	
	Tlista tabelaHash[TAM], exemplo;
	
	for(i=0; i<TAM; i++){
		inicializarlista(&tabelaHash[i]);
	}
		
	do {
		op = menu();
		
		switch(op){
		   case 1: adicionarHash(&tabelaHash, TAM); break;
		   case 2: printHash(&tabelaHash, TAM); break;
		   case 3: removerHash(&tabelaHash, TAM); break;	
		}
		limparBuffer();
		printf("\nPressione qualquer tecla para continuar. . .");
		char c = getchar();
	    system("@cls||clear");
		
	} while(op != 0);
	
	
    }
