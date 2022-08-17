// -- Luiz Eduardo Marchiori --

#ifndef lista_H_
#define lista_H_


typedef struct tipoElemento TNo;

typedef char string[40];

typedef struct tipoElemento{
	unsigned long long int registro;
	string nome;
	TNo *proximo;
}TNo;

typedef struct tipolista {
	int total;
	TNo *primeiro, *ultimo;
}Tlista;

void adicionarEm(Tlista * lista, unsigned long long int registro, string nome);

void inicializarlista(Tlista *lista);

void adicionarElemento(Tlista *lista);

void printlista(Tlista *lista);

void removerElemento(Tlista *lista);

#endif // lista_H_
