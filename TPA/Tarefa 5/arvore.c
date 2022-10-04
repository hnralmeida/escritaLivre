
/*
=========================================================================================
AUTOR: 	Henrique Almeida de Oliveira

Disciplina: TÃ©cnico de ProgramaÃ§Ã£o AvanÃ§ada
Professor: Eduardo Max Amaral

Objetivos;
â€¢ Representar computacionalmente uma Ãrvore BinÃ¡ria.
â€¢ Implementar um algoritmo que gere e manipule uma Ãrvore BinÃ¡ria com matricula e nome
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
			ImplementaÃ§Ã£o
*/

// Funcao padrao, tira caracteres indesejados para leitura de strings
void limparBuffer(){
    char c;
    while((c= getchar()) != '\n' && c != EOF);
}

// Funcao recursiva, retorna struct no encontrada correspondente a parametro nome
TTree *digThrowTree(TTree* node, string name){
	if (node==NULL){ 	// nesse ponto indica que nao foi possivel encontrar o no procurado pelo parametro
		return NULL; 	
	}else if(!strcmp(node->name, name)){ 	// se compativel com o parametro, retorna o no desejado
		return node;						
	}else if(strcmp(node->name, name)>0){	// procura nos valores menores que o no
		digThrowTree(node->left, name);
	}else{									// procura nos valores maiores que o no
		digThrowTree(node->right, name);
	}//if
}

int treeHigh(TTree* node){
	if (node==NULL){
		return 0;
	}else{
		node->nl = treeHigh(node->left) + 1;
		node->nr = treeHigh(node->right) + 1;
		int i = (node->nl > node->nr) ? node->nl : node->nr;
		return i;
	}
}

// funcao que inicializa a sentinela vaiza e com 0 nos
void inicitializeSentinel(TSentinel *L){
	L->root = NULL;
	L->total = 0;
	L->high = 0;
}

// serie de subfuncao de inseraNaSentinela implementa rotacoes
TTree* rotateLL(TTree *raiz){
	TTree* no = (raiz)->left;
	(raiz)->left = no->right;
	no->right = raiz;
	(raiz) = no;
	return raiz;
}

TTree* rotateRR(TTree *raiz){
	TTree* no = (raiz)->right;
	(raiz)->right = no->left;
	no->left = (raiz);
	(raiz) = no;
	return raiz;
}

TTree* rotateLR(TTree *raiz){
	raiz = rotateRR((raiz)->left);
	raiz = rotateLL(raiz);
	return raiz;
}

TTree* rotateRL(TTree *raiz){
	raiz = rotateLL(raiz->right);
	raiz = rotateRR(raiz);
	return raiz;
}

// subfunÃ§Ã£o de insertRegister, chamada por insereNaArvore
// retorna um ponteiro para o no com os atributos desejados
TTree *inicializaTree(string nome, string reg){
	TTree *no = (TTree *)malloc(sizeof(TTree));
	no->right = NULL;
    no->left=NULL;
	no->nl=0;
	no->nr=0;
	strcpy(no->name, nome);
	strcpy(no->reg, reg);
	return no;
}

// calcula a altura de um nó 
int alturaNo(TTree *raiz) {
    if (raiz==NULL) // se não existe o nó, retorna a altura -1
        return -1;
    else
        return ( (raiz->nl) > (raiz->nr) ? (raiz->nl) : (raiz->nr) );
}

// calcula o fator de balanceamento 
int fatorBalanceamento(TTree *node) { 
	// labs retorna o valor absoluto
    return labs(alturaNo(node->left) - alturaNo(node->right));
}

// subfuncao de insertRegister, chamada por insereNaSentinela
// encontra o pai do no inserido
TTree *insereNaArvore(TTree **node, string nome, string reg){
	if((*node)==NULL){	// verifica se o no pode ser inserido
		(*node) = inicializaTree(nome, reg);

	}else if(strcmp(nome, (*node)->name)>0){ // procura nos nos a direita um no NULL
		(*node)->right = insereNaArvore(&(*node)->right, nome, reg);
	}else { // procura nos nos a esquerda um no NULL
		(*node)->left = insereNaArvore(&(*node)->left, nome, reg);
	}
	
    return (*node);
}

// subfuncao de insertRegister, chamada por insertRegister
// manipula a sentinela e automatiza insersao
void insereNaSentinela(TSentinel **L, string nome, string reg){
	(*L)->total++;
	TTree* root = (*L)->root;
	 root = insereNaArvore(&(*L)->root, nome, reg);
	
	if(fatorBalanceamento((*L)->root) > 1) {
		if(reg < (*L)->root->left->reg)
			root = rotateLL((*L)->root);
		else
			root = rotateLR((*L)->root);
	}else if(fatorBalanceamento((*L)->root) < 1){
		if(reg < (*L)->root->left->reg)
			root = rotateRR((*L)->root);
		else
			root = rotateRL((*L)->root);
	}	
}

// Funcao para inserir um aluno com nome e matricula
void insertRegister(TSentinel *L){
    string nome, reg;
	TTree* valid;

	// recebe dados do usuario
	printf("\nDigite o nome para adicionar: ");
	limparBuffer();
	scanf("%[^\n]s", nome);
	printf("\nDigite o matrícula para adicionar: ");
    limparBuffer();
	scanf("%[^\n]s", reg);
	
	// verifica se ja nao existe o valor passado na arvore
	valid = digThrowTree(L->root, nome); 
	L->high = treeHigh(L->root);
 	
	if (valid==NULL) insereNaSentinela(&L, nome, reg); // se nao estiver adicionado, adiciona o registro
	else printf("Valor ja existe na arvore");
	printf("\naltura no esq: %d\naltura no direito %d", alturaNo(L->root->left)+1, alturaNo(L->root->right)+1);
}

// SubfunÃ§Ã£o de preOrderList
void digTreePre(TTree* node){
	if(node==NULL) return;
	printf("\n%s \t %s", node->reg, node->name);
    digTreePre(node->left);
	digTreePre(node->right);
}

// Listar alunos em PrÃ©-ordem por nome
void preOrderList(TSentinel *L){
	TTree *aux = L->root;

	printf("\n============================");
	printf("\n\tLista de Alunos (Pre-Ordem)");
	printf("\n\tAltura: %d", L->high);
	printf("\n============================");

	digTreePre(aux);
}

// SubfunÃ§Ã£o de inOrderList
void digTreeEm(TTree* node){
	if(node==NULL) return;
	digTreeEm(node->left);
	printf("\n%s \t %s", node->reg, node->name);
	digTreeEm(node->right);
}

// Listar alunos Em-ordem por nome
void inOrderList(TSentinel *L){
	TTree *aux = L->root;

	printf("\n============================");
	printf("\n\tLista de Alunos (Em Ordem)");
	printf("\n\tAltura: %d", L->high);
	printf("\n============================");

	digTreeEm(aux);
}

// SubfunÃ§Ã£o de posOrderList
void digTreePos(TTree* node){
	if(node==NULL) return;
	digTreePos(node->left);
	digTreePos(node->right);
    printf("\n%s \t %s", node->reg, node->name);
}

// Listar alunos em pos ordem por nome
void posOrderList(TSentinel *L){
	TTree *aux = L->root;

	printf("\n============================");
	printf("\n\tLista de Alunos (Pos-Ordem)");
	printf("\n\tAltura: %d", L->high);
	printf("\n============================");

	digTreePos(aux);
}

// Consultar alunos por Nome
void searchNode(TSentinel *L){
	TTree *aux = L->root;
	//se nao for uma arvore vazia, procura na arvore
	if(aux == NULL){
		printf("\nArvore Vazia!");
	}else{
		printf("\nQual pessoa deseja procurar?\n> ");
		string nome;
		limparBuffer();
		scanf("%[^\n40]s", nome);
		TTree *x = digThrowTree(aux, nome); //se o nome existir, retorna no com o nome
		if (x==NULL){ // se no nao existir, variavel esta null
			printf("\nNao encontrado!");
		}else{
			printf("\nEncontrado!");
			printf("\n%s \t %s", x->reg, x->name);
		}//if...else
	}//if...else
}

// subfuncao de RemoveNode, chamada por removerArvore
// utilizada para pegar o nÃ³ mais a direita da subarvore esquerda do nÃ³ que serÃ¡ removido
TTree *raizDireita(TTree **no){
	if ((*no)->right != NULL){ // navega a direita atÃ© achar o no mais a direita
		return raizDireita(&(*no)->right);
	} else { // retorna no que estava mais a direita
		TTree *aux1 = *no;
		if ((*no)->left != NULL)
			*no = (*no)->left;
		else
			*no = NULL;
		return aux1;
	}
}

// subfuncao de RemoveNode, remove da Ã¡rvore o aluno do parametro
void removerArvore(TSentinel *L, TTree **raiz, string apagar){
	int resposta = 0;
	if (*raiz == NULL){ // se a arvore estiver vazia, nao ha o que remover
		printf("\nNome nao encontrado!\n\n");
		return;
	}

	if (strcmp(apagar, (*raiz)->name) < 0){ //verifica nos nos se o nome vem antes (A-Z)
		removerArvore(L, &(*raiz)->left, apagar);
	} else if (strcmp(apagar, (*raiz)->name) > 0){ //verifica nos nos se o nome vem depois (A-Z)
        removerArvore(L, &(*raiz)->right, apagar);
    } else { // nome para apagar esta no no atual, confirmar
        printf("\n============================");
        printf("\n   Apagar %s?\n   1 - Sim\n   0 - Nao\n\n-> ", (*raiz)->name);
        scanf("%i", &resposta);
        printf("\n============================");

        if (resposta){ // se confirmado exclusao
            TTree *aux = (*raiz);
            if (((*raiz)->left == NULL) && ((*raiz)->right == NULL)){ //verifica se tem filhos
                free(aux);
                (*raiz) = NULL;
                if (L->root == (*raiz)) (L->root)=NULL;
            } else if ((*raiz)->left == NULL){ // so um filho a direita
                if (L->root == (*raiz)) (L->root)=(*raiz)->right;
                (*raiz) = (*raiz)->right;
                aux->right = NULL;
                free(aux);
                aux = NULL;
            }else if ((*raiz)->right == NULL){ // so um filho a esquerda
                    if (L->root == (*raiz)) (L->root)=(*raiz)->left;
                    (*raiz) = (*raiz)->left;
                    aux->left = NULL;
                    free(aux);
                    aux = NULL;
            }else { // dois filhos, chama funcao que desloca o filho a esquerda mais a direita
                if (L->root == (*raiz)) (L->root)=aux;
                aux = raizDireita(&(*raiz)->left);
                aux->left = (*raiz)->left;
                aux->right = (*raiz)->right;
                free((*raiz));
                (*raiz) = aux;
            }//if...else if...else if...else
            printf("\n   %s apagado(a) !\n\n", apagar);
        } else {
            printf("\n============================");
            printf("\n%s nÃ£o apagado (a)", apagar);
        }//if...else 
    }//if...else if...else
}

// Remover aluno da arvore
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
		L->high = treeHigh(L->root);
		L->total--;
	}//if...else
}

// funcao que adiciona valores default
void automatico(TSentinel *L){
	string nome[10] = {"Yuri Duarte","Luiz Felipe Nascimento", "Calebe Fernandes" ,
						"Maria VitÃ³ria Pires", "Diogo da Mota","Yasmin da Paz" ,
						"Maria Julia Sales","Juliana Duarte", "Kaique da Rocha",
						"Lucas Gabriel Sales"};

	string matricula[10] = {"0x01", "0x02", "0x03", "0x04", "0x05", "0x06", "0x07",
							"0x08", "0x09", "0x0A"};
	int i;
	for (i=0; i<10; i++)
		insereNaArvore(&(L->root), nome[i], matricula[i]);
	L->high = treeHigh(L->root);
}

// calcula o numero de linhas do aquivo
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

// usa os valores do arquivo f para registrar no banco de dados
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
	L->high = treeHigh(L->root);
}

// subfuncao de saveBase, percorre todos nos salvando os dados
void saveThrow(TTree* node, FILE* file){
    if(node==NULL) return;
	saveThrow(node->left, file);
    fprintf(file, "%s\n",  node->name);
    fprintf(file, "%s\n", node->reg);
	saveThrow(node->right, file);
}

// Funcao apra salvar os dados de um arquivo
void saveBase(TSentinel *L){
    FILE *file;
    unsigned long long int i = L->total;
    file = fopen("Lista_Aluno_Matricula_Atual.txt", "w");
    TTree *node = L->root; 
	// Salva os dados de Aluno em cada lista da tabela hash 
    saveThrow(node, file);
    fclose(file);
}
