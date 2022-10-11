/*
=========================================================================================
AUTOR: 	Henrique Almeida de Oliveira
Disciplina: Técnico de Programação Avançada
Professor: Eduardo Max Amaral

Objetivos:
- Implementar uma lista de adjacência para representar uma Matriz Adjacência.
- Implementar uma lista de adjacência para representar uma Matriz Adjacência (grafo 
ponderado -> matriz de pesos).

=========================================================================================
			Tipo Abstrato de Dados
*/

#ifndef GRAFO_H_
#define GRAFO_H_

typedef struct adjacent Tadjacent;

typedef struct vertex Tvertex;

typedef struct list Tlist;

typedef struct graph Tgraph;

typedef char string[40];

typedef struct adjacent{
    Tvertex* vertex;
    int distance;
}Tadjacent;

typedef struct vertex {
    string city_name;
	Tadjacent* adjacent;
    int number_adjacent;
}Tvertex;

typedef struct list {
	Tvertex* item;
	Tlist* next;
}Tlist;

typedef struct graph {
	int total;
	Tlist* list;
}Tgraph;

// Funções padrão
void limparBuffer();

// Função de grafos
void inicitializeGraph(Tgraph* g);
void insertCity(Tgraph*g);
void printCity(Tgraph* g);

#endif