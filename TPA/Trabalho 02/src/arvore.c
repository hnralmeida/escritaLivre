/*
=========================================================================================
AUTOR: 	Henrique Almeida de Oliveira

Disciplina: Técnico de Programação Avançada
Professor: Eduardo Max Amaral

Objetivos;
• Representar computacionalmente uma Árvore Binária.
• Implementar um algoritmo que gere e manipule uma Árvore Binária com matricula e nome
(Aluno).
=========================================================================================
*/

#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>
#include "arvore.h"

/*
=========================================================================================
			Implementação
*/

void limparBuffer(){
    char c;
    while((c= getchar()) != '\n' && c != EOF);
}

// Funcao recursiva, retorna struct no encontrada correspondente a parametro
TTree *digThrowTree(TTree* node, string name){
	if (node==NULL){
		return NULL;
	}else if(!strcmp(node->name, name)){
		return node;
	}else if(strcmp(node->name, name)>0){
		digThrowTree(node->left, name);
	}else{
		digThrowTree(node->right, name);
	}
}

void inicializaSentinel(TSentinel *L){
	L->root = NULL;
	L->total = 0;
}

// subfunção de inseraNaArvore, modifica os ponteiros
TTree *inicializaTree(string nome, string reg){
	TTree *no = (TTree *)malloc(sizeof(TTree));
	no->right = NULL;
    no->left=NULL;
	strcpy(no->name, nome);
	strcpy(no->reg, reg);
	return no;
}

// subfunção de inseraNaLista,
TTree *insereNaArvore(TTree **node, string nome, string reg){
	if((*node)==NULL){
		(*node) = inicializaTree(nome, reg);
	}else if(strcmp(nome, (*node)->name)>0){
		(*node)->right = insereNaArvore(&(*node)->right, nome, reg);
	}else {
		(*node)->left = insereNaArvore(&(*node)->left, nome, reg);
	}
	return (*node);
}

// subfunção de inserePessoa, implementa automatização como função direta
void insereNaSentinela(TSentinel **L, string nome, string reg){
	(*L)->total++;
	(*L)->root = insereNaArvore(&(*L)->root, nome, reg);
}

// Funcao para inserir uma pessoa com registro
void insertRegister(TSentinel *L){
    string nome, reg;
	TTree* valid;

	printf("\nDigite o nome e matricula para adicionar: ");
	limparBuffer();
	scanf("%[^\n40]s", nome);
    limparBuffer();
	scanf("%[^\n40]s", reg);
	
	// verifica se já não existe o valor passado na árvore
	valid = digThrowTree(L->root, nome); 
 	
	if (valid==NULL) insereNaSentinela(&L, nome, reg);
	else printf("Valor ja existe na arvore");
}

// Subfunção de listaMatriculaPre
void digTreePre(TTree* node){
	if(node==NULL) return;
	printf("\n%s \t %s", node->reg, node->name);
    digTreePre(node->left);
	digTreePre(node->right);
}

// Listar Pessoas em Pré-ordem
void preOrderList(TSentinel *L){
	TTree *aux = L->root;

	printf("\n============================");
	printf("\n\tLista de Alunos (Pre-Ordem)");
	printf("\n============================");

	digTreePre(aux);

}

// Subfunção de listaNomeEO
void digTreeEm(TTree* node){
	if(node==NULL) return;
	digTreeEm(node->left);
	printf("\n%s \t %s", node->reg, node->name);
	digTreeEm(node->right);
}

// Listar Pessoas Em-ordem
void inOrderList(TSentinel *L){
	TTree *aux = L->root;

	printf("\n============================");
	printf("\n\tLista de Alunos (Em Ordem)");
	printf("\n============================");

	digTreeEm(aux);

}

// Subfunção de listaMatricula, entra na árvore para imprimir em ordem
void digTreePos(TTree* node){
	if(node==NULL) return;
	digTreePos(node->left);
	digTreePos(node->right);
    printf("\n%s \t %s", node->reg, node->name);
}

// Listar Pessoas por ordem crescente de matrícula
void posOrderList(TSentinel *L){
	TTree *aux = L->root;

	printf("\n============================");
	printf("\n\tLista de Alunos (Pos-Ordem)");
	printf("\n============================");

	digTreePos(aux);

}

// Consultar Pessoa por Nome
void searchNode(TSentinel *L){

	TTree *aux = L->root;
	if(aux == NULL){
		printf("\nArvore Vazia!");
	}else{
		printf("\nQual pessoa deseja procurar?\n> ");
		string nome;
		limparBuffer();
		scanf("%[^\n40]s", nome);
		TTree *x = digThrowTree(aux, nome);
		if (x==NULL){
			printf("\nNao encontrado!");
		}else{
			printf("\nEncontrado!");
			printf("\n%s \t %s", x->reg, x->name);
		}
	}
}

//subfuncao de removerGeral utilizada para pegar o nó mais a direita da subarvore esquerda do nó que será removido
TTree *raizDireita(TTree **no){
	if ((*no)->right != NULL){
		return raizDireita(&(*no)->right);
	} else {
		TTree *aux1 = *no;
		if ((*no)->left != NULL)
			*no = (*no)->left;
		else
			*no = NULL;
	return aux1;
	}
}

//subfuncao de removerLista, remove da árvore a pessoa
void removerArvore(TSentinel *L, TTree **raiz, string apagar){
	int resposta = 0;
	if (*raiz == NULL){
		printf("\nNome nao encontrado!\n\n");
		return;
	}

	if (strcmp(apagar, (*raiz)->name) < 0){
		removerArvore(L, &(*raiz)->left, apagar);
	} else if (strcmp(apagar, (*raiz)->name) > 0){
        removerArvore(L, &(*raiz)->right, apagar);
    } else {
        printf("\n============================");
        printf("\n   Apagar %s?\n   1 - Sim\n   0 - Nao\n\n-> ", (*raiz)->name);
        scanf("%i", &resposta);
        printf("\n============================");
        if (resposta){
            TTree *aux = (*raiz);
            if (((*raiz)->left == NULL) && ((*raiz)->right == NULL)){
                free(aux);
                (*raiz) = NULL;
                if (L->root == (*raiz)) (L->root)=NULL;
            } else if ((*raiz)->left == NULL){
                if (L->root == (*raiz)) (L->root)=(*raiz)->right;
                (*raiz) = (*raiz)->right;
                aux->right = NULL;
                free(aux);
                aux = NULL;
            }else if ((*raiz)->right == NULL){
                    if (L->root == (*raiz)) (L->root)=(*raiz)->left;
                    (*raiz) = (*raiz)->left;
                    aux->left = NULL;
                    free(aux);
                    aux = NULL;
            }else {
                if (L->root == (*raiz)) (L->root)=aux;
                aux = raizDireita(&(*raiz)->left);
                aux->left = (*raiz)->left;
                aux->right = (*raiz)->right;
                free((*raiz));
                (*raiz) = aux;
            }
            printf("\n   %s apagado(a) !\n\n", apagar);
        } else {
            printf("\n============================");
            printf("\n%s não apagado (a)", apagar);
        }
    }
}

// Remover Pessoa das estruturas
void RemoveNode(TSentinel *L){

	TTree *aux = L->root;

	if(aux == NULL){
		printf("\nLista Vazia!");
	}else{
		printf("\nQual pessoa deseja remover?\n> ");
		string nome;
		limparBuffer();
		scanf("%[^\n40]s", nome);
		removerArvore(L, &aux, nome);
		L->total--;
	}
}

void automatico(TSentinel *L){
	string nome[10] = {"Yuri Duarte","Luiz Felipe Nascimento", "Calebe Fernandes" ,
						"Maria Vitória Pires", "Diogo da Mota","Yasmin da Paz" ,
						"Maria Julia Sales","Juliana Duarte", "Kaique da Rocha",
						"Lucas Gabriel Sales"};

	string matricula[10] = {"0x01", "0x02", "0x03", "0x04", "0x05", "0x06", "0x07",
							"0x08", "0x09", "0x0A"};
	int i;
	for (i=0; i<10; i++)
		insereNaArvore(&(L->root), nome[i], matricula[i]);
}

unsigned long long int calcSize(FILE* f){
    string s;
	unsigned long long int i=0;

	// Move o cursor para o inicio do arquivo
	fseek(f, 0, SEEK_SET);

	// Percorre todas linhas do arquivo e adiciona 1 no contador 
	// para cada linha percorrida
	while (!feof(f)){
      	fscanf(f, " %[^\n]s", s);
    	i++;
  	}//while

	// Move o cursor para o inicio do arquivo
	fseek(f, 0, SEEK_SET);

	return i;
}

void initializeDB(TSentinel *L, FILE* f, unsigned long long int size){
	string name, reg;
	int i=0;

	// Percorre todo arquivo pegando dados do aluno
	while (!feof(f)){
		// Toda linha impar eh o nome de um aluno
      	fscanf(f, " %[^\n]s", name);
		// Toda linha par eh o numero de uma matricula
		fscanf(f, " %[^\n]s", reg);
		// Adiciona o Aluno na lista correspondete da tabela hash
		insereNaArvore(&(L->root), name, reg);
  	}//while
}

void saveThrow(TTree* node, FILE* file){
    if(node==NULL) return;
	saveThrow(node->left, file);
    fprintf(file, "%s\n",  node->name);
    fprintf(file, "%s\n", node->reg);
	saveThrow(node->right, file);
}

void saveBase(TSentinel *L){
    FILE *file;
    unsigned long long int i = L->total;
    file = fopen("Lista_Aluno_Matricula_Atual.txt", "w");
    TTree *node = L->root; 
	// Salva os dados de Aluno em cada lista da tabela hash 
    saveThrow(node, file);
    fclose(file);
}