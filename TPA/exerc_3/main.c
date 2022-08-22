/*
=========================================================================================
AUTORES:
			Henrique Almeida de Oliveira
			Luiz Eduardo Marchiori
Disciplina: Topicos de Programacao Avancada

Biblioteca de lista Simplesmente encadeada com sentinela
=========================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
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
    printf("0 - SAIR (Encerrar programa sem salvar alteracoes).\n\n");
    printf("1 - Adicionar.\n");
    printf("2 - Procurar estudante.\n");
    printf("3 - Remover.\n");
	printf("4 - Salvar.\n\n");
    printf("\tInforme OPCAO desejada: ");

    scanf("%d",&opcao);

	if (opcao==222) return 222;
	if ((opcao > 4) || (opcao < 0)){
		printf("\n\n\n");
		printf("\n+-------------------------------------------------+");
		printf("\n|   ERRO:                                         |");
		printf("\n|                                                 |");
		printf("\n|   OPCAO INVALIDA!!!                             |");
		printf("\n|                                                 |");
		printf("\n|   Tente outra vez.                              |");
		printf("\n+-------------------------------------------------+\n\n");
		system("PAUSE");
	}
	return opcao;
}

void main(){

	int op, i=0;
	unsigned long long int size;

	setlocale(LC_ALL, "");

	// ABRIR ARQUIVO
	FILE *fileLoad;
	fileLoad = fopen( "Lista_Aluno_Matricula.txt" , "r" );  // Cria um arquivo texto para gravação

	if (fileLoad == NULL){
		printf("Problemas na Leitura do arquivo\n");
		return;
	}

	// INICIAR TABELA HASH
	size = 1.5*calcSize(fileLoad);
	fseek(fileLoad, 0, SEEK_SET);
	Tlist tabHash[size];

	for(i=0; i<size; i++){
		initializeList(&tabHash[i]);
	}

	// INICIAR BANCO DE DADOS
	fseek(fileLoad, 0, SEEK_SET);
	initializeDB(tabHash, fileLoad, size);
	fclose(fileLoad);

	// MENU DE USUÁRIO
	do {
		op = menu();

		switch(op){
		   case 1: addElementHash(tabHash, size); break;
		   case 2: searchStudent(tabHash, size); break;
		   case 3: removeHash(tabHash, size); break;
		   case 4: saveFile(tabHash, size);
		   case 222: printHash(tabHash, size); break;
		}//switch
		limparBuffer();
		printf("\nPressione qualquer tecla para continuar. . .");
		char c = getchar();
	    system("@cls||clear");

	} while(op != 0);

}
