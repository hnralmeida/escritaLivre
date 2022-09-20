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

typedef struct tipoSentinel {
	int total;
	TTree* root;
}TSentinel;

// Funções padrão
int menu();
void limparBuffer();

// Função de Lista SEABB
void initializeSentinel(TSentinel *L); // inicia uma lista com raiz nula
void insertTree(TSentinel *L); // insere um registro a partir da entrada padrão
void printDepthFirst(TSentinel *L); //percurso em profundidade
void printInOrder(TSentinel *L); //percurso in order
void printPosOrder(TSentinel *L); //percurso pos order
void removeTree(TSentinel *L); //remove um valor da arvore
void searchValue(TSentinel *L); //procura um valor na arvore
void automatico(TSentinel *L); //adiciona valores padrao na arvore

#endif // BINARIO_H_
