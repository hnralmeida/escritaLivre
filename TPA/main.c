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
#include"lista.h"

/*
=========================================================================================
			Exemplo usando sentinelaSimples.h
*/

void main(){	
	Tlist example;
	initializeList(&example);   
		
	do {
		op = menu();
		
		switch(op){
		   case 1: int value;
			   do {
				printf("Coloque o valor que você quer adicionar: );
				scanf("%d, &value);
			    }while (value < 0);   
			    addIn(&example, value); break;
		   case 2: printList(&example); break;
		   case 3: removeElement(&example); break;	
		}//switch
		
	} while(op != 0);
	
    }
