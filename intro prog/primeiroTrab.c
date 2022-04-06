#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

#define MAX 1024

void criptografar(char* mensagem){
	int i, j, p, q;
	char c, geraden[MAX], ungeraden[MAX];

	for(i=0; i<MAX; i++){
        c = mensagem[i];
        if (c == '\0') i = MAX;
		switch(c){
			case 'a':
				mensagem[i] = '@';
				break;
			case '@':
				mensagem[i] = 'a';
				break;
			case 'o':
				mensagem[i] = '0';
				break;
			case '0':
				mensagem[i] = 'o';
				break;
            default:
                break;
		}
	}

	for(i=0; i<MAX/2; i++){
        p = 2*i;
        q = 2*i+1;
        ungeraden[i] = mensagem [p];
        geraden[i] = mensagem [q];
	}

	for(i=0; i<MAX/2; i++) {
            if (geraden[i]=='\0'){
              j = i%2 ? i-1: i-2;
              i = MAX;
            }
	}

	for(i=0; i<j+1; i++){
        p = 2*i;
        q = 2*i+1;
        mensagem [p] = ungeraden[i];
        mensagem [q] = geraden[j-i];
	}
}

void main(){
    setlocale(LC_ALL, " ");
	char msg[MAX];

	printf("\nDigite uma Mensagem: ");
	scanf(" %[^\n]s", msg);
	printf("\nMensagem antes: %s \nCriptografando...", msg);

	criptografar(msg);
	printf("\n\nMensagem criptografada: %s", msg);

	criptografar(msg);
	printf("\n\nMensagem descriptografada: %s \n", msg);
}
