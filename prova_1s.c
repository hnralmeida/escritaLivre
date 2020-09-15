/*Um palíndromo (de letras ou algarismos) é uma sequência de símbolos que
 representa a mesma sequência se lida da esquerda para a direita ou da
 direita para a esquerda. Por exemplo: ana.
Faça um programa que leia uma palavra e identifique se a mesma é um palíndromo.*/

#include<stdio.h>
#include<string.h>

int checker (char *word);

void main(){
    char palavra[20];
    printf("\nEntre uma palavra, direi se ela ser um palindromo\n");

    fflush(stdin);
    scanf("%s", palavra);
    fflush(stdin);

    if(!checker(palavra)){
        printf("\n A palavra %s ser palindromo", palavra);
    }else{
        printf("\nA palavra %s nao ser palindromo", palavra);
    }
}

int checker(char *word){
    int i = 0, j =0;
    while(word[i]!= '\0'){
        i++;
    }

    char palavra_s[i];
    char palavra[i];
    for(j=0; j<(i); j++){
        palavra_s[j] = word[j];
        palavra[j] = word[j];
    }
    fflush(stdin);
    char temp;
    j=0;
    i=i-1;
    while (j < i) { //esse trecho do código pode apresentar algum problema com determinadas palavras,
        temp = palavra[j]; // alguns teclados parecem armazenar lixo no final da string
        palavra[j] = palavra[i];
        palavra[i] = temp;
        j++;
        i--;
    }
    fflush(stdin);
    return strcmp(palavra, palavra_s);
}
