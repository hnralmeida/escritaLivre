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
	addIn(&example, 1);
	addIn(&example, 2);
	addIn(&example, 3);
	addIn(&example, 4);
	printList(&example);
	removeElement(&example);
	removeElement(&example);
	printList(&example);
}
