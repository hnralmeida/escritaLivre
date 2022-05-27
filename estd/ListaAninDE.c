/*
=========================================================================================
AUTORES: 	Henrique Almeida de Oliveira
		Luiz Eduardo Marchiori
Disciplina: Estrutura de Dados
Professor: Vanderson José Idelfonso Silva
Programa em linguagem C que implementa uma Lista aninhada formada em sua camada mais externa por uma lista duplamente encadeada de Cursos.
=========================================================================================
*/

#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>

/*
=========================================================================================
			Tipo Abstrato de Dados
*/

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
	int total;
}TAluno;

typedef struct tipoTurma {
	TTurma *prox, *ante;
	string nomeTurma;
	TAluno *alunos;
	int total;
}TTurma;

typedef struct tipoCurso {
	TCurso *prox, *ante;
	string nomeCurso;
	TTurma *turmas;
	int total;
}TCurso;

typedef struct Lista {
	TCurso *ini, *fim;
	int total;
}lista;

int menu (lista *l);
int menuCurso (lista *l);
int menuTurma(lista *l);
int menuAluno (lista *l);
int menuDisciplina (lista *l);
int menuPrincipal (lista *l);

// inicializa lista com ponteiros nulos
void inicializaLista(lista *l);
// adiciona curso passada como parâmetro na lista 
void adicionaCurso(lista *l, string nomeCurso);
// exclui o curso passado como parâmetro
void excluirCurso(lista *l, string nomeCurso);
// lista cursos na lsita
void listarCurso(lista* l);
// adiciona turma no curso passado como parâmetro lista 
void adicionaTurma(lista *l, string nomeCurso, string nomeTurma);
// exclui a turma passado como parâmetro
void excluirTurma(lista *l, string nomeCurso, string nomeTurma);
// lista todas turmas em seus respectivos cursos
void listarTurma(lista* l);
// adiciona aluno na turma e curso passados como parâmetro lista 
void adicionaAluno(lista *l, string nomeCurso, string nomeTurma, string nomeAluno, char gender);
// exclui aluno passado como parâmetro
void excluirAluno(lista *l, string nomeCurso, string nomeTurma, string nomeAluno);
// lista todos alunos em seus respectivos cursos e turmas
void listarAluno(lista* l);
// adiciona disciplina no aluno passado como parâmetro lista
void adicionaDisciplina(lista *l, string nomeCurso, string nomeTurma, string nomeAluno, string nomeDisciplina, int cargaHoraria, string semestreLetivo);
// exclui disciplina passado como parâmetro
void excluirDisciplina(lista *l, string nomeCurso, string nomeTurma, string nomeAluno, string nomeDisciplina);
// lista todas disciplinas de um aluno
void listarDisciplina(lista *l, string nomeCurso, string nomeTurma, string nomeAluno); 
/*
=========================================================================================
			MAIN
*/
int main (){
	lista l;
	inicializaLista(&l);
	setlocale(LC_ALL, "");
	while(1){
		menuPrincipal(&l);
	}
}

/*
=========================================================================================
			IMPLEMENTAÇÃO DAS FUNÇÕES
*/

void defaultList(lista *l){
	adicionaCurso(l, "SI");
	adicionaCurso(l, "Arq");
	adicionaCurso(l, "Bio");
	adicionaCurso(l, "Med");
	adicionaCurso(l, "Fis");
	adicionaTurma(l, "SI", "V1");
	adicionaTurma(l, "Arq", "V2");
	adicionaTurma(l, "Bio", "V3");
	adicionaTurma(l, "Med", "V4");
	adicionaTurma(l, "Fis", "V5");
	adicionaTurma(l, "SI", "V6");
	adicionaTurma(l, "Arq", "V7");
	adicionaTurma(l, "Bio", "V8");
	adicionaTurma(l, "Med", "V9");
	adicionaTurma(l, "Fis", "V10");
	adicionaAluno(l, "SI", "V1", "Ana", 'M');
	adicionaAluno(l, "Arq", "V2", "Bia", 'M');
	adicionaAluno(l, "Bio", "V3", "Ana Julia", 'M');
	adicionaAluno(l, "Bio", "V3", "Ana Xulia", 'M');
	adicionaAluno(l, "Med", "V4", "Paulo Henrique", 'H');
	adicionaAluno(l, "Fis", "V5", "Ana Cristina", 'M');
	adicionaAluno(l, "SI", "V6", "Gustavo Henrique", 'H');
	adicionaAluno(l, "Arq", "V7", "Ana Paula", 'M');
	adicionaAluno(l, "Bio", "V8", "Pedro Henrique", 'H');
	adicionaAluno(l, "Med", "V9", "Ana Lima", 'M');
	adicionaAluno(l, "Fis", "V10", "Paulo Gustavo", 'H');
}

void limparBuffer(){
    char c;
    while((c= getchar()) != '\n' && c != EOF);
}

int menuDisciplina (lista *l){
	int opcao, ch;
	string curso, turma, nome, disciplina, semestre;
	//system("CLS");
	do{
		printf("\n======================================");
		printf("\nBem vindo ao menu de Disciplinas!");
		printf("\n======================================");
		printf("\nSelecione uma opção: ");
		printf("\n0 - Ir para o menu principal\n1 - Inserir disciplina\n2- Excluir disciplina\n3- Listar disciplinas de um aluno\n");
		printf("\n======================================");
		printf("\nSua opção: ");
		scanf("%d", &opcao);
	}while ((opcao < 0) || (opcao > 3));
	if (opcao ==0){
		menuPrincipal(l);
		}
	switch(opcao){
	case 1: 
		printf("\nDigite o Curso: ");
		limparBuffer();
		scanf("%[^\n40]s", curso);
		printf("\nDigite a Turma: ");
		limparBuffer();
		scanf("%[^\n40]s", turma);
		printf("\nDigite o nome do aluno: ");
		limparBuffer();
		scanf("%[^\n40]s", nome);
		printf("Add: %s", nome);
		printf("\nDigite a disciplina: ");
		limparBuffer();
		scanf("%[^\n40]s", disciplina);
		adicionaDisciplina(l, curso, turma, nome, disciplina, ch, semestre);
		break;
	case 2: 
		printf("\nDigite o Curso: ");
		limparBuffer();
		scanf("%[^\n40]s", curso);
		printf("\nDigite a Turma: ");
		limparBuffer();
		scanf("%[^\n40]s", turma);
		printf("\nDigite o nome do aluno: ");
		limparBuffer();
		scanf("%[^\n40]s", nome);
		printf("\nDigite a disciplina: ");
		limparBuffer();
		scanf("%[^\n40]s", disciplina);
		excluirDisciplina(l, curso, turma, nome, disciplina); 
		break;
	case 3:
		printf("\nDigite o Curso: ");
		limparBuffer();
		scanf("%[^\n40]s", curso);
		printf("\nDigite a Turma: ");
		limparBuffer();
		scanf("%[^\n40]s", turma);
		printf("\nDigite o nome do aluno: ");
		limparBuffer();
		scanf("%[^\n40]s", nome);
		listarDisciplina(l, curso, turma, nome); 
		break;
	}
}

int menuAluno (lista *l){
	int opcao;
	string curso, turma, nome;
	char gender;
	//system("CLS");
	do{
		printf("\n======================================");
		printf("\nBem vindo ao menu de Alunos!");
		printf("\n======================================");
		printf("\nSelecione uma opção: ");
		printf("\n0 - Ir para o menu principal\n1 - Inserir Aluno\n2- Excluir Aluno\n3- Listar todos os alunos\n");
		printf("\n======================================");
		printf("\nSua opção: ");
		scanf("%d", &opcao);
	}while ((opcao < 0) || (opcao > 3));
	if (opcao ==0){
		menuPrincipal(l);
		}
	switch(opcao){
	   case 1: 
		printf("\nDigite o Curso: ");
		limparBuffer();
		scanf(" %s", curso);
		printf("\nDigite a Turma: ");
		limparBuffer();
		scanf(" %s", turma);
		printf("\nDigite o nome do aluno: ");
		limparBuffer();
		scanf(" %s", nome);
		printf("\nDigite o genero do aluno: ");
		limparBuffer();
		scanf(" %c", &gender);
		adicionaAluno(l, curso, turma, nome, gender);
		break;
	   case 2: 
		printf("\nDigite o Curso: ");
		limparBuffer();
		scanf(" %s", curso);
		printf("\nDigite a Turma: ");
		limparBuffer();
		scanf(" %s", turma);
		printf("\nDigite o nome do aluno: ");
		limparBuffer();
		scanf(" %s", nome);
		excluirAluno(l, curso, turma, nome); 
		break;
	   case 3: 
		listarAluno(l); 
		break;
	}
}

int menuTurma(lista *l){
	int opcao;
	string curso, turma;
	//system("CLS");
	do{
		printf("======================================\n");
		printf("Bem vindo ao menu de Turma!\n");
		printf("======================================\n");
		printf("Selecione uma opção: \n");
		printf("0 - Ir para o menu principal\n1 - Inserir Turma\n2- Excluir Turma\n3- Listar todas as turmas\n");
		printf("\n=====================================");
		printf("\nSua opção: ");
		scanf("%d", &opcao);
	}while ((opcao < 0) || (opcao > 3));
	if (opcao ==0){
		menuPrincipal(l);
		}
	switch(opcao){
	   case 1: 
		printf("\nDigite o Curso: ");
		limparBuffer();
		scanf(" %s", curso);
		printf("\nDigite a Turma: ");
		limparBuffer();
		scanf(" %s", turma);
		adicionaTurma(l, curso, turma); 
		break;
	   case 2: 
		printf("\nDigite o Curso: ");
		limparBuffer();
		scanf(" %s", curso);
		printf("\nDigite a Turma: ");
		limparBuffer();
		scanf(" %[^ ]s", turma);
		excluirTurma(l, curso, turma); 
		break;
	   case 3: 
		listarTurma(l); 
		break;
	}
}

int menuCurso (lista *l){
	int opcao;
	string curso;
	//system("CLS");
	do{
		printf("======================================\n");
		printf("Bem vindo ao menu de Cursos!\n");
		printf("======================================\n");
		printf("Selecione uma opção: \n");
		printf("0 - Ir para o menu principal\n1 - Inserir Curso\n2- Excluir Curso\n3- Lista todos os cursos\n");
		printf("\n======================================");
		printf("\nSua opção: ");
		scanf("%d", &opcao);
	}while ((opcao < 0) || (opcao > 3));
	switch(opcao){
	   case 1: 
   		printf("\nDigite o Curso: ");
   		string curso;
   		limparBuffer();
   		scanf(" %[^\n40]s", curso);
		adicionaCurso(l, curso); 
		break;
	   case 2: 
		printf("\nDigite o Curso: ");
		limparBuffer();
		scanf(" %[^\n40]s", curso);
		excluirCurso(l, curso); 
		break;
	   case 3: 
   		listarCurso(l); 
		break;
	}
	if (opcao ==0){
		return -1;
	}
}

int menu (lista *l){
	int opcao;
	do{
		printf("======================================\n");
		printf("Bem vindo ao menu!\n");
		printf("======================================\n");
		printf("Selecione uma opção: \n");
		printf("0 - Sair\n1 - Cursos\n2- Turmas\n3- Alunos\n4- Disciplinas\n");
		printf("\n======================================");
		printf("\nSua opção: ");
		scanf("%d", &opcao);
		if(opcao==256) return opcao;
	}while ((opcao < 0) || (opcao > 4));
	return opcao;
}

int menuPrincipal (lista *l){
	int op;
	op = menu(l);
	switch(op){
	   case 1: menuCurso(l); break;
	   case 2: menuTurma(l); break;
	   case 3: menuAluno(l); break;
	   case 4: menuDisciplina(l); break;
	   case 256: defaultList(l); break;
		}
	if (op == 0){
		exit(0);
	}
	limparBuffer();
	printf("\nPressione qualquer tecla para continuar. . .");
	char c = getchar();
    system("@cls||clear");
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
	c->total=0;
}

void adicionaCurso(lista *l, string nomeCurso){
	TCurso *no = (TCurso *)malloc(sizeof(TCurso));
	inicializaCurso(no, nomeCurso);
	l->total++;
    
	if(l->ini==NULL){
		l->ini = no;
		l->fim = no;
	}else{
		TCurso *aux = l->ini;
		while(aux->prox!=NULL&&(strcmp(nomeCurso, aux->nomeCurso)>0))
            aux = aux->prox;
            
		if(aux->prox == NULL){
        	aux->prox = no;
        	no->ante = aux;
        	l->fim = no;
		}else if(aux->ante == NULL){
			no->prox = aux;
			aux->ante = no;
			l->ini = no;
		}else{
			TCurso* aux1 = aux->ante;
			no->prox = aux;
			no->ante = aux1;
			aux->ante = no;
			aux1->prox = no;
		}
	}
}

void excluirCurso(lista *l, string nomeCurso){
	if(l->ini==NULL){
		printf("\nLista Vazia: não há nada para excluir");
		return;
	}else{
		TCurso *aux = l->ini;
		l->total--;
		if(aux == NULL){
			printf("\nNão há cursos para remover na lista");
		}else{
			while(aux->prox!=NULL&&(strcmp(nomeCurso, aux->nomeCurso))) aux = aux->prox;
		
			if(aux==NULL){
				printf("\nCurso não encontrado: revise informações antes de prosseguir");
			}else if(aux->prox == NULL){
				TCurso *aux1 = aux->ante;
				aux1->prox = NULL;
				free(aux);
			}else if(aux->ante == NULL){
				TCurso *aux1 = aux->prox;
				aux1->ante = NULL;
				l->ini = aux1;
				free(aux);
			}else{
				TCurso *aux1 = aux->ante;
				TCurso *aux2 = aux->prox;
				aux1->prox = aux2;
				aux2->ante = aux1;
				free(aux);
			}
		
		}
	}
}

void listarCurso(lista* l){
	TCurso* aux;
	aux = l->ini;
	int i, max = l->total;
	printf("\n============================");
	printf("\n\tLista de Cursos");
	printf("\n============================");
	for (i=0; i<max; i++){
		printf("\n- %s", aux->nomeCurso);
		aux = aux->prox;
	}
}

void inicializaTurma(TTurma* c, string nomeTurma){
	c->ante=NULL;
	c->prox=NULL;
	c->alunos=NULL;
	c->total=0;
	strcpy(c->nomeTurma, nomeTurma);
}

void adicionaTurma(lista *l, string nomeCurso, string nomeTurma){
	TTurma *no = (TTurma *)malloc(sizeof(TTurma));
	inicializaTurma(no, nomeTurma);
    
	if(l->ini==NULL){
		printf("\nLista Vazia: crie um curso antes");
		return;
	}else{
		TCurso *aux = l->ini;
		while(aux!=NULL && strcmp(aux->nomeCurso, nomeCurso)) aux = aux->prox;
		if(aux == NULL){
			printf("\nCurso não encontrado: adicione o curso antes");
			return;
		}
		aux->total++;
		
		if(aux->turmas == NULL){
			aux->turmas = no;
		}else{
			TTurma *aux1 = aux->turmas;
			while(aux1->prox!=NULL&&(strcmp(nomeTurma, aux1->nomeTurma)>0))
			aux1 = aux1->prox;
	            
			if(aux1->prox == NULL){
				aux1->prox = no;
				no->ante = aux1;
			}else if(aux1->ante == NULL){
				aux1->ante = no;
				no->prox = aux1;
				aux->turmas = no;
			}else{
				TTurma* aux2 = aux1->ante;
				no->prox = aux1;
				no->ante = aux2;
				aux1->ante = no;
				aux2->prox = no;
			}
		}
	}
}

void excluirTurma(lista *l, string nomeCurso, string nomeTurma){
	if(l->ini==NULL){
		printf("\nLista Vazia: não há nada para excluir");
		return;
	}else{
		TCurso *aux = l->ini;
		while(aux!=NULL && strcmp(aux->nomeCurso, nomeCurso)) aux = aux->prox;
		if(aux == NULL){
			printf("\nCurso não encontrado: revise informações antes de prosseguir");
			return;
		}

		TTurma *aux1 = aux->turmas;
		aux->total--;
		if(aux == NULL){
			printf("\nNão há turmas para remover nessa curso");
		}else{
			while(aux1->prox!=NULL&&(strcmp(nomeTurma, aux1->nomeTurma))) aux1 = aux1->prox;
		
			if(aux1==NULL){
				printf("\nTurma não encontrada: revise informações antes de prosseguir");
			}else if(aux1->prox == NULL){
				TTurma *aux2 = aux1->ante;
				aux2->prox = NULL;
				free(aux1);
			}else if(aux1->ante == NULL){
				TTurma *aux2 = aux1->prox;
				aux2->ante = NULL;
				aux->turmas = aux2;
				free(aux1);
			}else{
				TTurma *aux2 = aux1->ante;
				TTurma *aux3 = aux1->prox;
				aux2->prox = aux3;
				aux3->ante = aux2;
				free(aux1);
			}
		
		}
	}
}

void listarTurma(lista* l){
	TCurso* aux;
	aux = l->ini;
	int i, max = l->total;
	printf("\n============================");
	printf("\n\tLista de Turmas");
	printf("\n============================");
	for (i=0; i<max; i++){
		TTurma* aux1;
		aux1 = aux->turmas;
		
		printf("\n- %s", aux->nomeCurso);
		int j, max1 = aux->total;
		
		for(j=0; j<max1; j++){
			printf("\n\t- %s", aux1->nomeTurma);
			aux1 = aux1->prox;
		}
		aux = aux->prox;
	}
}

void inicializaAluno(TAluno* c, string nomeAluno, char gender){
	c->ante=NULL;
	c->prox=NULL;
	c->disciplinas=NULL;
	c->genero = gender;
	c->total=0;
	strcpy(c->nome, nomeAluno);
}

void adicionaAluno(lista *l, string nomeCurso, string nomeTurma, string nomeAluno, char gender){
	TAluno *no = (TAluno *)malloc(sizeof(TAluno));
	inicializaAluno(no, nomeAluno, gender);
    
	if(l->ini==NULL){
		printf("\nLista Vazia: crie um curso antes");
		return;
	}else{
		TCurso *aux = l->ini;
		while(aux!=NULL && strcmp(aux->nomeCurso, nomeCurso)) aux = aux->prox;
		if(aux == NULL){
			printf("\nCurso não encontrado: adicione o curso antes");
			return;
		}
		
		TTurma *aux1 = aux->turmas;
		while(aux1!=NULL && strcmp(aux1->nomeTurma, nomeTurma)) aux1 = aux1->prox;
		if(aux1 == NULL){
			printf("\nTurma não encontrada: adicione a turma antes");
			return;
		}
		aux1->total++;
		
		TAluno *aux2 = aux1->alunos;
		if(aux2 == NULL){
			aux1->alunos = no;
		}else{
			while(aux2->prox!=NULL&&(strcmp(nomeAluno, aux2->nome)<0)) aux2 = aux2->prox;
		
			if(aux2->prox == NULL){
				aux2->prox = no;
				no->ante = aux2;
			}else if(aux2->ante == NULL){
				aux2->ante = no;
				no->prox = aux2;
				aux1->alunos = no;
			}else{
				no->prox = aux2->prox;
				aux2->prox = no;
				no->prox->ante = no;
				no->ante = aux2;
			}
		
		}
	}
}

void excluirAluno(lista *l, string nomeCurso, string nomeTurma, string nomeAluno){
	if(l->ini==NULL){
		printf("\nLista Vazia: não há nada para excluir");
		return;
	}else{
		TCurso *aux = l->ini;
		while(aux!=NULL && strcmp(aux->nomeCurso, nomeCurso)) aux = aux->prox;
		if(aux == NULL){
			printf("\nCurso não encontrado: revise informações antes de prosseguir");
			return;
		}
		
		TTurma *aux1 = aux->turmas;
		while(aux1!=NULL && strcmp(aux1->nomeTurma, nomeTurma)) aux1 = aux1->prox;
		if(aux1 == NULL){
			printf("\nTurma não encontrada: revise informações antes de prosseguir");
			return;
		}
		aux1->total--;
		
		TAluno *aux2 = aux1->alunos;
		if(aux2 == NULL){
			printf("\nNão há alunos para remover nessa turma");
		}else{
			while(aux2->prox!=NULL&&(strcmp(nomeAluno, aux2->nome))) aux2 = aux2->prox;
		
			if(aux2==NULL){
				printf("\nAluno(a) não encontrado(a): revise informações antes de prosseguir");
			}else if(aux2->prox == NULL){
				TAluno *aux3 = aux2->ante;
				aux3->prox = NULL;
				free(aux2);
			}else if(aux2->ante == NULL){
				TAluno *aux3 = aux2->prox;
				aux3->ante = NULL;
				aux1->alunos = aux3;
				free(aux2);
			}else{
				TAluno *aux3 = aux2->ante;
				TAluno *aux4 = aux2->prox;
				aux3->prox = aux4;
				aux4->ante = aux3;
				free(aux2);
			}
		
		}
	}
}

void listarAluno(lista* l){
	TCurso* aux;
	aux = l->ini;
	int i, max = l->total;
	printf("\n============================");
	printf("\n\tLista de Alunos");
	printf("\n============================");
	for (i=0; i<max; i++){
		TTurma* aux1 = aux->turmas; 
		printf("\n-Curso: %s", aux->nomeCurso);		
		int j, max1 = aux->total;
		for(j=0; j<max1;j++){
			printf("\n\t-Turma: %s", aux1->nomeTurma);
			TAluno* aux2 = aux1->alunos;
			int k, max2 = aux1->total;
			for(k=0; k<max2; k++){
				printf("\n\t\t-Nome: %s", aux2->nome);
				aux2 = aux2->prox;
			}
			aux1 = aux1->prox;
		}
		aux = aux->prox;
	}
}

void inicializaDisciplina(TDisciplina* c, string nomeDisciplina, int cargaHoraria, string semestreLetivo){
	c->ante=NULL;
	c->prox=NULL;
	c->cargaHoraria = cargaHoraria;
	strcpy(c->semestreLetivo, semestreLetivo);
	strcpy(c->nome, nomeDisciplina);
}

void adicionaDisciplina(lista *l, string nomeCurso, string nomeTurma, string nomeAluno, string nomeDisciplina, int cargaHoraria, string semestreLetivo){
	TDisciplina *no = (TDisciplina *)malloc(sizeof(TDisciplina));
	inicializaDisciplina(no, nomeDisciplina, cargaHoraria, semestreLetivo);
    
	if(l->ini==NULL){
		printf("\nLista Vazia: crie um curso antes");
		return;
	}else{
		TCurso *aux = l->ini;
		while(aux!=NULL && strcmp(aux->nomeCurso, nomeCurso)) aux = aux->prox;
		if(aux == NULL){
			printf("\nCurso não encontrado: adicione o curso antes");
			return;
		}
		
		TTurma *aux1 = aux->turmas;
		while(aux1!=NULL && strcmp(aux1->nomeTurma, nomeTurma)) aux1 = aux1->prox;
		if(aux1 == NULL){
			printf("\nTurma não encontrada: adicione a turma antes");
			return;
		}
		
		TAluno *aux2 = aux1->alunos;
		
		while(aux2!=NULL && strcmp(aux2->nome, nomeAluno)) aux2 = aux2->prox;
		if(aux2 == NULL){
			printf("\nAluno(a) não encontrado(a): adicione Aluno(a) antes");
			return;
		}

		aux2->total++;
		TDisciplina *aux3 = aux2->disciplinas;
		if(aux3 == NULL){
			aux2->disciplinas = no;
		}else{		
			aux3->prox = no;
			no->ante = aux3;
		}
	}
}

void excluirDisciplina(lista *l, string nomeCurso, string nomeTurma, string nomeAluno, string nomeDisciplina){
	if(l->ini==NULL){
		printf("\nLista Vazia: não há nada para excluir");
		return;
	}else{
		TCurso *aux = l->ini;
		while(aux!=NULL && strcmp(aux->nomeCurso, nomeCurso)) aux = aux->prox;
		if(aux == NULL){
			printf("\nCurso não encontrado: revise informações antes de prosseguir");
			return;
		}
		
		TTurma *aux1 = aux->turmas;
		while(aux1!=NULL && strcmp(aux1->nomeTurma, nomeTurma)) aux1 = aux1->prox;
		if(aux1 == NULL){
			printf("\nTurma não encontrada: revise informações antes de prosseguir");
			return;
		}
		
		TAluno *aux2 = aux1->alunos;
		while(aux2!=NULL && strcmp(aux2->nome, nomeDisciplina)) aux2 = aux2->prox;
		if(aux2 == NULL){
			printf("\nAluno(a) não encontrado(a): revise informações antes de prosseguir");
			return;
		}
		aux2->total--;
		
		TDisciplina *aux3 = aux2->disciplinas;
		if(aux3 == NULL){
			printf("\nNão há disciplinas para remover desse aluno");
		}else{
			while(aux3->prox!=NULL&&(strcmp(nomeDisciplina, aux3->nome))) aux3 = aux3->prox;
		
			if(aux3==NULL){
				printf("\nAluno(a) não encontrado(a): revise informações antes de prosseguir");
			}else if(aux3->prox == NULL){
				TDisciplina *aux4 = aux3->ante;
				aux4->prox = NULL;
				free(aux3);
			}else if(aux3->ante == NULL){
				TDisciplina *aux4 = aux3->prox;
				aux4->ante = NULL;
				aux2->disciplinas = aux4;
				free(aux3);
			}else{
				TDisciplina *aux4 = aux3->ante;
				TDisciplina *aux5 = aux3->prox;
				aux4->prox = aux5;
				aux5->ante = aux4;
				free(aux3);
			}
		
		}
	}
}

void listarDisciplina(lista *l, string nomeCurso, string nomeTurma, string nomeAluno){
	int i, max;
	TCurso *aux = l->ini;
	
	while(aux!=NULL && strcmp(aux->nomeCurso, nomeCurso)) aux = aux->prox;
	if(aux == NULL){
		printf("\nCurso não encontrado: revise informações antes de prosseguir");
		return;
	}
	
	TTurma *aux1 = aux->turmas;
	while(aux1!=NULL && strcmp(aux1->nomeTurma, nomeTurma)) aux1 = aux1->prox;
	if(aux1 == NULL){
		printf("\nTurma não encontrada: revise informações antes de prosseguir");
		return;
	}
	
	TAluno *aux2 = aux1->alunos;
	while(aux2!=NULL && strcmp(aux2->nome, nomeAluno)) aux2 = aux2->prox;
	if(aux2 == NULL){
		printf("\nAluno(a) não encontrado(a): revise informações antes de prosseguir");
		return;
	}
	
	printf("\n======================================");
	printf("\n\tLista de Disciplinas do Aluno");
	printf("\n======================================");
	max = aux2->total;
	TDisciplina* aux3 = aux2->disciplinas;
	printf("\nCurso: %s\tTurma: %s\nNome: %s\n-Disciplinas:", aux->nomeCurso, aux1->nomeTurma, aux2->nome);
	for(i=0; i<max; i++){
		printf("\n\t- %s", aux3->nome);
		aux2 = aux2->prox;
	} 
}
