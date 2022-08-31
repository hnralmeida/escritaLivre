3/*
=========================================================================================
AUTOR:	Henrique Almeida de Oliveira
Disciplina: Topicos de Programacao Avancada

					Trabalho 01 – Tabela Hash

Biblioteca de lista Simplesmente encadeada com sentinela
=========================================================================================
*/

#ifndef HASHOPEN_H_
#define HASHOPEN_H_

/*
=========================================================================================
			Tipo Abstrato de Dados
*/

/* Estrutura de elementos, cada uma representa um aluno com nome (name) e matricula (reg) 
*/
typedef struct typeElement Tnode;

typedef struct typeElement{
	int reg;
	int flag;
	int oc;
}Tnode;

/* Estrutura de lista dos elementos alunos */
typedef struct typeList {
	int total;
	int size;
	Tnode *vetor;
}HashTable;

/* inicializa lista com ponteiros nulos */
void initializeList(HashTable *list, int size);

/* adiciona valor passado na lista */
void addIn(HashTable * list, int reg);

/* implementa adicao de cursos */
void addElement(HashTable *list);

/* imprimir valores na lista */
void prinHashTable(HashTable *list);

/* implementa a remocao valores da lista */
void removeElement(HashTable *list);

/* remove valor passado da lista */
void removeIn(HashTable * list, int reg);

#endif // HASHOPEN_H_
