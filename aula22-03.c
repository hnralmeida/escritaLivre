/*
	HENRIQUE ALMEIDA DE OLIVEIRA

		22-03-2022
		
		ESTRUTURA DE DADOS - V02 - VANDERSON
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 9

typedef char string[TAM];

typedef struct grafo
{
	string nome;
    string vertice[TAM];
	int adjacencias[TAM][TAM];
} TRegistro;

void iniciaExemplo(TRegistro* R){
	strcpy(R->nome, "Exemplos");
	strcpy(R->vertice[0], "Ana");
	strcpy(R->vertice[1], "Cintia");
	strcpy(R->vertice[2], "Paula");
	strcpy(R->vertice[3], "José");
	strcpy(R->vertice[4], "Carlos");
	strcpy(R->vertice[5], "Sofia");
	strcpy(R->vertice[6], "Neide");
	strcpy(R->vertice[7], "Asdrúbal");
	strcpy(R->vertice[8], "Jambira");
	
	int parse[TAM][TAM] = {0,1,1,1,0,0,0,0,0,
					1,0,0,0,1,0,0,0,0,
					1,0,0,0,1,1,1,1,0,
					1,0,0,0,0,1,0,0,0,
					0,1,1,0,0,0,0,0,0,
					0,0,1,1,0,0,0,0,0,
					0,0,1,0,0,0,0,0,0,
					0,0,1,0,0,0,0,0,1,
					0,0,0,0,0,0,0,1,0};
			
	int i, j;		
	for (i=0; i<TAM; i++){
		for (j=0; j<TAM; j++){
			R->adjacencias[i][j] = parse[i][j];
		}
	}
}

void imprimir(TRegistro *R){
	int i, j;
	printf("AMIZADES NA REDE SOCIAL %s\n_____________________________\n", R->nome);
	for (i=0; i<TAM; i++){
		for (j=0; j<TAM; j++){
			if(R->adjacencias[i][j]&&i>j) printf("%s é amigo de %s\n", R->vertice[i], R->vertice[j]);
		}
	}
}

int localizarUser (string nome, TRegistro *R){
	int i, n;
	for(i=0; i<TAM; i++){
		if (strcmp(nome, R->vertice[i])) n=i;
	}
	printf("Usuário: %s\nNúmero: %d", R->vertice[i], n);
	return i;
}

void amigosDe(string nome, TRegistro *R){
	int i, user, count=0, amigos[TAM];
	
	user = localizarUser(nome, R);
	
	for(i=0; i<TAM; i++){
		if (R->adjacencias[user][i]){
			amigos[count]=i;
			count++;
		} 
	}
	
	if(count == 0){
		printf("%s não tem amigos", R->vertice[user]);
	}else if(count == 1){
		printf("%s tem como amigo %s", R->vertice[user], R->vertice[(amigos[0])]);
	}else if(count>1){
		printf("%s tem como amigo", R->vertice[user]);
		for(i=0; i<count-2;i++){
			printf(" %s, ", R->vertice[(amigos[i])]);
		}
		printf(" %s e %s.", R->vertice[(amigos[i+1])], R->vertice[(amigos[i+2])]);
	}
}

void menu(TRegistro *R){
	printf("\n_____________________________\nSelecione uma opção");
	printf("\n_____________________________");
	printf("\n0-Sair\n1-Imprimir tudo\n2-Imprimir amigos de ...\n");
	
	int number, loop =1;
	string nome;
	
	scanf("%d", &number);
	
	while(loop){
		switch(number){
		case 0:
			printf("Saindo do Menu");
			loop = 0;
			break;
			
		case 1:
			imprimir(R);
			
		case 2:
			//Imprimir amigos de __nome__
			//Sensível a acentuação e Case
			scanf(" %20[^\n]s", nome);
			printf("Analisando %s\n", nome);
			amigosDe(nome, R);
	}

	}	
}

void main(){
	
	setlocale(LC_ALL, "" );
	TRegistro redeSocial;
	
	iniciaExemplo(&redeSocial);
	
	menu(&redeSocial);
}
