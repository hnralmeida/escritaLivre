/*
=========================================================================================
AUTOR:	Henrique Almeida de Oliveira
Disciplina: Topicos de Programacao Avancada

					Trabalho 01 � Tabela Hash

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
}Tnode;

/* Estrutura de lista dos elementos alunos */
typedef struct typeList {
	int total;
	int size;
	Tnode **vetor;
}hashTable;

/* Calcula numero de linhas em um arquivo */
int calcSize(FILE* f);

/* inicializa lista com ponteiros nulos */
void initializeList(hashTable *list, int size);

/* carrega os dados de um arquivo no programa*/
void initializeDB(hashTable *list, FILE* f);

/* adiciona valor passado na lista */
void addIn(hashTable * list, int reg);

/* implementa adicao de cursos */
void addElement(hashTable *list);

/* imprimir valores na lista */
void printHashTable(hashTable *list);

/* implementa a remocao valores da lista */
void removeElement(hashTable *list);

/* remove valor passado da lista */
void removeIn(hashTable * list, int reg);

#endif // HASHOPEN_H_
