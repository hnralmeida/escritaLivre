/*
=========================================================================================
AUTORES: 	Henrique Almeida de Oliveira
			Luiz Eduardo Marchiori
Disciplina: Tópicos de Programação Avançada
Professor: 

Biblioteca de lista Simplesmente encadeada com sentinela
=========================================================================================
*/

#ifndef LISTA_H_
#define LISTA_H_

/*
=========================================================================================
			Tipo Abstrato de Dados
*/

typedef struct typeElement Node;

typedef struct typeElement{
	int value;
	Node *next;
}Node;

typedef struct List {
	int total;
	Node *first, *last;
}List;


void addIn(List * list, int value);

// inicializa lista com ponteiros nulos
void initializeList(List *list);

// adiciona curso passada como parâmetro na lista 
void addElement(List *list);

// imprimir valores na lista
void printList(List *list);

#endif // LISTA_H_
