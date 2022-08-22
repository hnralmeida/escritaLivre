/*
=========================================================================================
AUTORES: 	
			Henrique Almeida de Oliveira
			Luiz Eduardo Marchiori
Disciplina: Topicos de Programacao Avancada

Biblioteca de HASH
=========================================================================================
*/

#ifndef HASH_H_
#define HASH_H_

/*
=========================================================================================
			Tipo Abstrato de Dados
*/

// adiciona um vetor na tabela hash
void addElementHash (Tlist list[], unsigned long long int size);

// imprimir valores na tabela hash
void printHash(Tlist list[], unsigned long long int size);

// remover valores da tabela hash
void removeHash(Tlist list[], unsigned long long int size); 

// calcula o hash 1.5 para a base de dados
 unsigned long long int calcSize(FILE* f);

// inicialiar hash a partir de banco de dados no ponto de onde parou
void initializeDB(Tlist list[], FILE* f, unsigned long long int size);

// procura na tabela hash pela matricula informada e retorna dados do aluno
void searchStudent(Tlist list[], unsigned long long int size);

// salva a tabela hash no arquivo Lista_Aluno_Matricula.txt 
void saveFile(Tlist vetor[], unsigned long long int size);

#endif // HASH_H_
