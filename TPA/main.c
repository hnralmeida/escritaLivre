/*
=========================================================================================
AUTORES: 	Henrique Almeida de Oliveira
			Luiz Eduardo Marchiori
Disciplina: Tópicos de Programação Avançada
Professor: 
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
	list l;
	initializeList(&l);
	addIn(&l, 1);
	addIn(&l, 2);
	addIn(&l, 3);
	addIn(&l, 4);
	printList(l);
}
