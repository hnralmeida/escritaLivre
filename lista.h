/*
=========================================================================================
AUTORES: 	Henrique Almeida de Oliveira
			Luiz Eduardo Marchiori
Disciplina: T�picos de Programa��o Avan�ada
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

typedef char string[40];

//typedef struct List list;

typedef struct typeElement node;

typedef struct typeElement{
	int value;
	node *next;
}node;

typedef struct List {
	int total;
	node *first, *last;
}list;

void addIn(list *L, int value);

// inicializa lista com ponteiros nulos
void initializeList(list *l);

// adiciona curso passada como par�metro na lista 
void addElement(list *l);

// imprimir valores na lista
void printList(list l);

#endif // LISTA_H_

