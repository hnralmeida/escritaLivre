/*
=========================================================================================
AUTORES: 	
			Henrique Almeida de Oliveira
			Luiz Eduardo Marchiori
Disciplina: Tópicos de Programação Avançada

Biblioteca de BINARIO
=========================================================================================
*/

#ifndef BINARIO_H_
#define BINARIO_H_

/*
=========================================================================================
			Tipo Abstrato de Dados
*/

typedef struct NoTree TTree;

typedef struct NoTree{
	int valor;
	TTree *pai;
	TTree *esq, *dir;
}TTree;

typedef char string[40];

typedef struct tipoLista {
	int total;
	TTree* root;
}TLista;

// Funções padrão
int menu();
void limparBuffer();

// Função de Lista SEABB
void initializeTree(TLista *L); // inicia uma lista com raiz nula
void insertTree(TLista *L); // insere um registro a partir da entrada padrão
void printDepthFirst(TLista *L); //percurso em profundidade
void printInOrder(TLista *L); //percurso in order
void printPosOrder(TLista *L); //percurso pos order
void removeTree(TLista *L); // 
void automatico(TLista *L); //

#endif // BINARIO_H_
