/*
=========================================================================================
AUTORES: 	
			Henrique Almeida de Oliveira
			Luiz Eduardo Marchiori
Disciplina: Tópicos de Programação Avançada

Biblioteca de lista Simplesmente encadeada com sentinela
=========================================================================================
*/

#ifndef LISTA_H_
#define LISTA_H_

/*
=========================================================================================
			Tipo Abstrato de Dados
*/

typedef struct typeElement Tnode;

typedef char string[40];

typedef struct typeElement{
	unsigned long long int reg;
	string name;
	Tnode *next;
}Tnode;

typedef struct typeList {
	int total;
	Tnode *first, *last;
}Tlist;

// subfuncao de addElement
void addIn(Tlist * list, unsigned long long int reg, string name);

// inicializa lista com ponteiros nulos
void initializeList(Tlist *list);

// adiciona curso passada como parâmetro na lista 
void addElement(Tlist *list);

// imprimir valores na lista
void printList(Tlist *list);

// remover valores da lista
void removeElement(Tlist *list);

#endif // LISTA_H_
