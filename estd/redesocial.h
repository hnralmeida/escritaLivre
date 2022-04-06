#ifndef REDESOCIAL_H_
#define REDESOCIAL_H_

#define TAM 9

typedef char string[20];

typedef struct grafo
{
	string nome;
    string vertice[TAM];
	int adjacencias[TAM][TAM];
} TRegistro;

void iniciaExemplo(TRegistro* R);

void imprimir(TRegistro *R);

void amigosDe(string nome, TRegistro *R);

void menu(TRegistro *R);

void solitarios(TRegistro *R);

void famosinhos(TRegistro *R);

void sugestoes(TRegistro *R);

#endif // REDESOCIAL_H_
