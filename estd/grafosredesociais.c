/*
	HENRIQUE ALMEIDA DE OLIVEIRA

		22-03-2022

		ESTRUTURA DE DADOS - V02 - VANDERSON
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "redesocial.h"

#define TAM 9

void main(){

	setlocale(LC_ALL, "" );
	TRegistro redeSocial;

	iniciaExemplo(&redeSocial);

	menu(&redeSocial);
}

void limparBuffer(){
    char c;
    while((c= getchar()) != '\n' && c != EOF);
}

void menu(TRegistro *R){

	int number, loop =1;
	string nome;

	while(loop){
		printf("\n_____________________________\nSelecione uma opção");
		printf("\n_____________________________");
		printf("\n0- Sair\n1- Imprimir tudo\n2- Imprimir amigos de ...");
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
                imprimir(R);
                break;

            case 2:
                //Imprimir amigos de __nome__
                //Sensível a acentuação e Case
                printf("\nPesquisar: ");
                limparBuffer();
                scanf(" %20[^\n]s", nome);
                amigosDe(nome, R);
                break;

            case 3:
                famosinhos(R);
                break;

            case 4:
                solitarios(R);
                break;

            case 5:
                sugestoes(R);
                break;
        }
        printf("\n\nPressione Enter Para Sair...");
        limparBuffer();
        char c = getchar();

        system("@cls||clear");
	}
}

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
	printf("\n_____________________________");
	printf("\nREDE SOCIAL %s", R->nome);
	printf("\n_____________________________");
	for (i=0; i<TAM; i++){
		for (j=0; j<TAM; j++){
			if(R->adjacencias[i][j]&&i>j) printf("\n%s é amigo de %s", R->vertice[i], R->vertice[j]);
		}
	}
}

int localizarUser (string nome, TRegistro *R){
	int i;
	for(i=0; i<TAM; i++){
		if (!strcmp(nome, R->vertice[i])) return i;
	}
	return -1;
}

/*int *friendlist(int* user, int* count, int amigos[TAM], TRegistro *R){
    int i;

	if(user==-1){
		printf("\nUsuário Inválido\n");
		return '\0';
	}

	for(i=0; i<TAM; i++){
        printf("\n%s", typeof(R->adjacencias[user][i]));
		if (R->adjacencias[user][i]){
			amigos[count]=i;
			count++;
		}
	}
	return amigos;
}*/

void amigosDe(string nome, TRegistro *R){
	int i, user, count=0, amigos[TAM]={-1};

    user = localizarUser(nome, R);

	if(user==-1){
		printf("\nUsuário Inválido\n");
		return;
	}

	for(i=0; i<TAM; i++){
		if (R->adjacencias[user][i]){
			amigos[count]=i;
			count++;
		}
	}

	if(count == 0){
		printf("\n%s não tem amigos", R->vertice[user]);
	}else if(count == 1){
		printf("\n%s tem como amigo %s", R->vertice[user], R->vertice[(amigos[0])]);
	}else if(count>1){
		printf("\n%s tem como amigo", R->vertice[user]);
		for(i=0; i<count-2;i++){
			printf(" %s,", R->vertice[(amigos[i])]);
		}
		printf(" %s e %s.", R->vertice[(amigos[i])], R->vertice[(amigos[i+1])]);
	}
}

// z é o tamanho do vetor v e im é o vetor com os numeros de usuarios
// n é o número de amigos que deve ser compardo aos atuais do vetor
// os maiores número devem ser adicionados em ordem descrescente

void runTop(int z, int *v, int n, int *im, int user){
	int aux, i;
	for(i = 0; i<z; i++){
		if (n>=v[i]){
			//passando numero de amigos do usuario
			aux = v[i];
			v[i] = n;
			n = aux;
			// passando usuário
			aux = im[i];
			im[i] = user;
			user = aux;
		}
	}
}

// Os 5 usuários mais famosinhos da rede social (em ordem decrescente de importância).
// Mais recente é mais relevante
void famosinhos(TRegistro *R){
	int maior[5]={0,0,0,0,0}, maiorAux[5]={0,0,0,0,0},i, j, count=0;

	for (i=0; i<TAM; i++){
		count = 0;
		for (j=0; j<TAM; j++){
			if(R->adjacencias[i][j]) count ++;
		}
		runTop(5, maiorAux, count,maior,i);
	}

	printf("\nOs cinco usuário mais famosinhos são:");
	for (i=0; i<5; i++){
		printf("\n%d° - %s", (i+1), R->vertice[(maior[i])]);
	}
}

// z é o tamanho do vetor v e im é o vetor com os numeros de usuarios
// n é o número de amigos que deve ser compardo aos atuais do vetor
// os menores número devem ser adicionados em ordem descrescente

void runPit(int z, int *v, int n, int *im, int user){
	int aux, i;
	for(i = 0; i<z; i++){
		if (n<v[i]){
			//passando numero de amigos do usuario
			aux = v[i];
			v[i] = n;
			n = aux;
			// passando usuário
			aux = im[i];
			im[i] = user;
			user = aux;
		}
	}
}

// Os 3 usuários mais solitários da rede social (em ordem decrescente de importância).
// Mais velho é menos relevante
void solitarios(TRegistro *R){
	int pitThree[3]={8,8,8}, pitThreeUser[3]={8,8,8}, i, j, count=0;

	for (i=0; i<TAM; i++){
		count = 0;
		for (j=0; j<TAM; j++){
			if(R->adjacencias[j][i]) count ++;
		}
		runPit(3, pitThree, count, pitThreeUser, i);
	}

	printf("\nOs três usuário mais solitários são:");
	for (i=2; i>-1; i--){
		printf("\n%d° - %s", (3-i), R->vertice[(pitThreeUser[i])]);
	}
}

int* removeRepeted(int* count, int* v){
    int i, j, aux=0, *pass, flag=1, tam=0;

    pass = (int*) malloc((*count)*sizeof(int));

    for(i=0; i<*count; i++){
        for(j=i+1; j<*count; j++){
            if(v[i]==v[j])flag=0;
        }
        if(flag){
            pass[tam] = v[i];
            tam++;
        }
    }

    pass = (int *) realloc(pass, tam*sizeof(int));

    for(i=0;i<tam;i++) printf("\nV[%d] = %d", i, pass[i]);

    return pass;
}

void sugestoes(TRegistro *R){
    int i, j, k, count, suggested[TAM];

    for (i=0; i<TAM; i++){
		count = 0;
		for (j=0; j<TAM; j++){
			if(R->adjacencias[j][i]){
                for(k=0; k<TAM; k++){
                    if(i!=k&&R->adjacencias[k][j]&&!R->adjacencias[k][i]){
                        suggested[count]=k;
                        count++;
                    }
                }
			}
		}

		if(count == 0){
            printf("\n%s não tem amigos sugeridos", R->vertice[i]);
        }else if(count == 1){
            printf("\n%s talvez conheça %s", R->vertice[i], R->vertice[(suggested[0])]);
        }else if(count>1){
            printf("\n%s talvez conheça", R->vertice[i]);
            for(k=0; k<count-2;k++){
                printf(" %s,", R->vertice[(suggested[k])]);
            }
            printf(" %s ou %s.", R->vertice[(suggested[k])], R->vertice[(suggested[k+1])]);
        }
	}
}
