/*
AUTORES: 	Henrique Almeida de Oliveira
			Luiz Eduardo Marchiori
Disciplina: Estrutura de Dados
Professor: Vanderson José Idelfonso Silva
Programa em linguagem C que implementa uma Lista aninhada formada em sua camada mais externa por uma lista duplamente encadeada de Cursos.
*/

#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>

typedef char string[40];

typedef struct Lista lista;

typedef struct tipoCurso TCurso;

typedef struct tipoDisciplina TDisciplina;

typedef struct tipoTurma TTurma;

typedef struct tipoAluno TAluno;

typedef struct tipoDisciplina {
	TDisciplina *prox, *ante;
	int cargaHoraria;
	string semestreLetivo, nome;
}TDisciplina;

typedef struct tipoAluno{
	string nome;
	char genero;
	TAluno *prox, *ante;
	TDisciplina *disciplinas;
}TAluno;

typedef struct tipoTurma {
	TTurma *prox, *ante;
	string nomeTurma;
	TAluno *alunos;
}TTurma;

typedef struct tipoCurso {
	TCurso *prox, *ante;
	string nomeCurso;
	TTurma *turmas;
}TCurso;

typedef struct Lista {
	TCurso *ini, *fim;
	int total;
}lista;

int menu (lista *l);
int menuCurso (lista *l);
int menuTurma(lista *l);
int menuAluno (lista *l);
int menuPrincipal (lista *l);

// inicializa lista com ponteiros nulos
void inicializaLista(lista *l);
// adiciona curso na lista passada como parâmetro
void adicionaCurso(lista *l, string nomeCurso);
void excluirCurso();
void listarCurso(lista* l);
void adicionaTurma(lista *l, string nomeCurso, string nomeTurma);
void excluirTurma();
void listarTurma(lista* l);
void adicionaAluno(lista *l, string nomeCurso, string nomeTurma, string nomeAluno, char gender);
void excluirAluno();
void listarAluno();
void adicionaDisciplina(lista *l, string nomeCurso, string nomeTurma, string nomeAluno, string nomeDisciplina);

int main (){
	lista l;
	inicializaLista(&l);
	while(1){
		menuPrincipal(&l);
	}
}

int menu (lista *l){
	int opcao;
	do{
		printf("------------------------\n");
		printf("Bem vindo ao menu!\n");
		printf("Selecione uma opção: \n");
		printf("0 - Sair\n1 - Cursos\n2- Turmas\n3- Alunos\n");
		scanf("%d", &opcao);
	}while ((opcao < 0) || (opcao > 3));
	return opcao;
}

int menuCurso (lista *l){
	int opcao;
	system("CLS");
	do{
		printf("------------------------\n");
		printf("Bem vindo ao menu de Cursos!\n");
		printf("Selecione uma opção: \n");
		printf("0 - Ir para o menu principal\n1 - Inserir Curso\n2- Excluir Curso\n3- Lista todos os cursos\n");
		scanf("%d", &opcao);
	}while ((opcao < 0) || (opcao > 3));
	switch(opcao){
	   case 1: adicionaCurso(l, "SI"); break;
	   case 2: excluirCurso(); break;
	   case 3: listarCurso(); break;
	}
	if (opcao ==0){
		menuPrincipal(l);
	}
}

int menuTurma(lista *l){
	int opcao;
	system("CLS");
	do{
		printf("------------------------\n");
		printf("Bem vindo ao menu de Turma!\n");
		printf("Selecione uma opção: \n");
		printf("0 - Ir para o menu principal\n1 - Inserir Turma\n2- Excluir Turma\n3- Listar todas as turmas\n");
		scanf("%d", &opcao);
	}while ((opcao < 0) || (opcao > 3));
	if (opcao ==0){
		menuPrincipal(l);
		}
	switch(opcao){
	   case 1: adicionaTurma(l, "SI", "2021"); break;
	   case 2: excluirTurma(); break;
	   case 3: listarTurma(); break;
		}
}

int menuAluno (lista *l){
	int opcao;
	system("CLS");
	do{
		printf("------------------------\n");
		printf("Bem vindo ao menu de Alunos!\n");
		printf("Selecione uma opção: \n");
		printf("0 - Ir para o menu principal\n1 - Inserir Aluno\n2- Excluir Aluno\n3- Listar todos os alunos\n");
		scanf("%d", &opcao);
	}while ((opcao < 0) || (opcao > 3));
	if (opcao ==0){
		menuPrincipal(l);
		}
	switch(opcao){
	   case 1: adicionaAluno(l, "SI", "2021", "Luiz"); break;
	   case 2: excluirAluno(); break;
	   case 3: listarAluno(); break;
	}
}

int menuPrincipal (lista *l){
	int op;
	//system("CLS");
		op = menu(l);
		switch(op){
		   case 1: menuCurso(l); break;
		   case 2: menuTurma(l); break;
		   case 3: menuAluno(l); break;
			}
		if (op == 0){
			exit(0);
		}
}

void inicializaLista(lista *l){
	l->ini = NULL;
	l->fim = NULL;
	l->total = 0;
}

void inicializaCurso(TCurso* c, string nomeCurso){
	c->ante=NULL;
	c->prox=NULL;
	c->turmas=NULL;
	strcpy(c->nomeCurso, nomeCurso);
}

void adicionaCurso(lista *l, string nomeCurso){
	TCurso *no = (TCurso *)malloc(sizeof(TCurso));
	inicializaCurso(no, nomeCurso);
    
	if(l->ini==NULL){
		l->ini = no;
	}else{
		TCurso *aux = no->prox;
		while(aux->prox!=NULL&&(strcmp(nomeCurso, aux->nomeCurso)<0))
            aux = aux->prox;
		aux->prox = no;
	}
}

void excluirCurso(){
	printf("Excluiu Curso\n");
}
void listarCurso(lista* l){
	printf("Listou Curso\n");
}

void inicializaTurma(TTurma* c, string nomeTurma){
	c->ante=NULL;
	c->prox=NULL;
	c->alunos=NULL;
	strcpy(c->nomeTurma, nomeTurma);
}

void adicionaTurma(lista *l, string nomeCurso, string nomeTurma){
	TTurma *no = (TTurma *)malloc(sizeof(TTurma));
    inicializaTurma(no, nomeTurma);
    
	if(l->ini==NULL){
		printf("Lista Vazia");
		return;
	}else{
		TCurso *aux = l->ini;
		while(aux!=NULL && strcmp(aux->nomeCurso, nomeCurso)) aux = aux->prox;
		if(aux == NULL){
			printf("Curso não encontrado");
			return;
		}
		
		if(aux->turmas == NULL){
			aux->turmas = no;
		}else{
			TTurma *aux1 = aux->turmas;
			while(aux1->prox!=NULL&&(strcmp(nomeTurma, aux1->nomeTurma)<0))
	            aux1 = aux1->prox;
	            
	        if(aux1->prox == NULL){
	        	aux1->prox = no;
	        	no->ante = aux1;
			}else{
				no->prox = aux1->prox;
				aux1->prox = no;
				no->prox->ante = no;
				no->ante = aux1;
			}
		}
	}
}

void excluirTurma(lista* l){
	printf("Excluiu Turma\n");
}

void listarTurma(lista* l){
	printf("Listou Turma\n");
}

void inicializaAluno(TAluno* c, string nomeAluno, char gender){
	c->ante=NULL;
	c->prox=NULL;
	c->disciplinas=NULL;
	c->genero = gender;
	strcpy(c->nomeAluno, nomeAluno);
}

void adicionaAluno(lista *l, string nomeCurso, string nomeTurma, string nomeAluno, char gender){
	TAluno *no = (TAluno *)malloc(sizeof(TAluno));
    inicializaAluno(no, nomeAluno);
    
	if(l->ini==NULL){
		printf("Lista Vazia");
		return;
	}else{
		TCurso *aux = l->ini;
		while(aux!=NULL && strcmp(aux->nomeCurso, nomeCurso)) aux = aux->prox;
		if(aux == NULL){
			printf("Curso não encontrado");
			return;
		}
		
		TTurma *aux1 = aux->turmas
		while(aux1!=NULL && strcmp(aux1->nomeTurma, nomeTurma)) aux1 = aux1->prox;
		if(aux1 == NULL){
			printf("Turma não encontrada");
			return;
		}
		
		
		//Consertar 
		TAluno *aux2 = aux1->alunos
		if(aux2 == NULL){
			aux2 = no;
		}else{
			while(aux2->prox!=NULL&&(strcmp(nomeAluno, aux2->nomeAluno)<0))
	            aux2 = aux2->prox;
	    
	            
	        if(aux2->prox == NULL){
	        	aux2->prox = no;
	        	no->ante = aux2;
			}else{
				no->prox = aux2->prox;
				aux2->prox = no;
				no->prox->ante = no;
				no->ante = aux2;
			}
		}
	}
}

void excluirAluno(){
	printf("Excluiu aluno\n");
}

void listarAluno(){
	printf("Alistou aluno\n");
}

