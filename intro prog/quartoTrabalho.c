#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

typedef struct Cliente cliente;

typedef struct Conta conta;

struct Cliente{
    char nome[100];
    char numero[15];
    char email[100];
};

struct Conta{
    char numero[15];
    float saldo;
    cliente usuario;
};

void limparBuffer(){
    char c;
    while((c= getchar()) != '\n' && c != EOF);
}

void upperCase(char* name){
    int i=0;
    while(name[i]!='\0'){
        name[i] = toupper(name[i]);
        i++;
    }
}

int posicaoConta(conta* banco, char* numero, int tamanho){
	int i;
	for(i=0; i<tamanho; i++){
		if (strcmp(banco[i].numero, numero) == 0){
			return i;
		}
	}
	return -1;
}

int posicaoNome(conta* banco, char* nome, int tamanho){
	int i;
	for(i=0; i<tamanho; i++){
		if (strcmp(banco[i].usuario.nome, nome) == 0){
			return i;
		}
	}
	return -1;
}

void limparConta (conta* banco, int excluir, int tamanho){
	int ultima = tamanho-1;
	strcpy(banco[excluir].numero, banco[ultima].numero);
	banco[excluir].saldo = 0;
	strcpy(banco[excluir].usuario.email, banco[ultima].usuario.email);
	strcpy(banco[excluir].usuario.nome, banco[ultima].usuario.nome);
	strcpy(banco[excluir].usuario.numero, banco[ultima].usuario.numero);

	banco[ultima].numero[0] = '\0';
	banco[ultima].saldo = 0;
	banco[ultima].usuario.email[0] = '\0';
	banco[ultima].usuario.nome[0] = '\0';
	banco[ultima].usuario.numero[0] = '\0';
}
//Inserir conta: ler os dados do cliente e o número da conta e inserir no vetor com o
//          	saldo ZERO. Não deixar inserir número de conta repetido.
conta* criarConta(conta* banco, int* tam, FILE* arq){
    if (feof(arq)){
        printf ("\nArquivo vazio");
        printf("\nAperte Qualquer Tecla...");
		getchar();
		return 0;
    }
    // Os printf e limparBuffer na sessão abaixo são para a versão sem leitura de arquivo
	//printf("\nEntre com os dados no Cliente\nNome: ");
	fscanf(arq," %99[^\n]s", banco[(*tam)].usuario.nome);
	//limparBuffer();
	upperCase(banco[(*tam)].usuario.nome);

	//printf("\nTelefone: ");
	fscanf(arq," %s", banco[(*tam)].usuario.numero);
	//limparBuffer();

	//printf("\nEmail: ");
	fscanf(arq, " %s", banco[(*tam)].usuario.email);
	//limparBuffer();
	upperCase(banco[(*tam)].usuario.email);

	do{
		//printf("\nNúmero da Conta: ");
		fscanf(arq, " %s", banco[(*tam)].numero);
    	//limparBuffer();
	}while(posicaoConta(banco, banco[(*tam)].numero, (*tam))!=-1);

	banco[(*tam)].saldo = 0;

	(*tam)++;

	return banco;
}

conta* inserir(conta* banco, int* tamanho, FILE* arq){
	if((*tamanho)%10){
	   banco = criarConta(banco, tamanho, arq);
    }else{
        banco = (conta*)realloc(banco, (*tamanho+10)*sizeof(struct Conta));
        banco = criarConta(banco, tamanho, arq);
	}
	return banco;
}
// Pesquisar por conta: pedir um número da conta e pesquisar no vetor, imprimindo
//           	todos os dados do cliente e da conta.
void pesquisarConta(conta* banco, int tamanho){
	char numero[15];
	printf("\nEntre o número da Conta: ");
	scanf(" %s", numero);
	limparBuffer();

	int x = posicaoConta(banco, numero, tamanho);
    if(x == -1){
        printf("Conta não encontrada");
    }else{
        printf("\nCliente: %s\nTelefone: %s", banco[x].usuario.nome, banco[x].usuario.numero);
        printf("\tEmail: %s\nConta: %s\tSaldo: %f", banco[x].usuario.email, banco[x].numero, banco[x].saldo);
    }
}
// Pesquisar por nome: pedir o nome do cliente e pesquisar no vetor, imprimindo
//            	todos os dados do cliente e da conta.
void pesquisarNome(conta* banco, int tamanho){
	char nome[100];
	printf("\nEntre o Nome a ser pesquisado: ");
	scanf(" %s", nome);
	upperCase(nome);
	limparBuffer();

	int x = posicaoNome(banco, nome, tamanho);

    if(x == -1){
        printf("Conta não encontrada");
    }else{
        printf("\nCliente: %s\nTelefone: %s", banco[x].usuario.nome, banco[x].usuario.numero);
        printf("\tEmail: %s\nConta: %s\tSaldo: %f", banco[x].usuario.email, banco[x].numero, banco[x].saldo);
    }
}
// Depositar: pedir o número da conta e o valor a depositar. Pesquisar o n�mero da
//         		Conta no vetor e somar o saldo com o valor do dep�sito.

void depositar(conta* banco, int tamanho){
	char conta[15];
	float valor;
	printf("\nEntre o número da Conta: ");
	scanf(" %s", conta);
	limparBuffer();
	upperCase(conta);
	int x = posicaoConta(banco, conta, tamanho);
	if(x == -1){
        printf("Conta não encontrada");
    }else{
		printf("\nEntre o valor a ser depositado: ");
		scanf("%f", &valor);
		banco[x].saldo += valor;
	}
}
// Sacar: pedir o número da conta e o valor a sacar. Pesquisar o número da conta no
//        		vetor e diminuir o saldo com o valor do saque, se houver saldo.
void sacar(conta* banco, int tamanho){
	char conta[15];
	float valor;
	printf("\nEntre o número da Conta: ");
	scanf(" %s", conta);
	limparBuffer();

	int x = posicaoConta(banco, conta, tamanho);

	if(x == -1){
        printf("Conta não encontrada");
		return;
	}

	printf("\nEntre o valor a ser sacado: ");
	scanf("%f", &valor);
	limparBuffer();
	upperCase(conta);

    if(banco[x].saldo >= valor){
		banco[x].saldo -= valor;
	}else{
		printf("Valor Insuficiente!");
	}
}
// Excluir uma conta: pedir o número da conta e excluir do vetor.
void excluir(conta* banco, int* tamanho, char* numero){
	int x = posicaoConta(banco, numero, *tamanho);

    if((*tamanho)==1){
    	free(banco);
		banco = NULL;
	}else if(!((*tamanho)%10)){
		limparConta(banco, x, *tamanho);
    }else{
    	banco = (conta*)realloc(banco, (*tamanho-10)*sizeof(struct Conta));
	}
	(*tamanho)--;
}
// Listar: mostrar todas as contas e seu respectivo saldo.
void listar(conta* banco, int* tamanho){
	int i;

	if(tamanho == 0) printf("\nNão há Clientes no momento");

	for ( i=0; i<*tamanho; i++){
        if(*banco[i].numero==' '){
            return;
        }
		printf("\nCliente: %s \nConta: %s \tSaldo: %.2f", banco[i].usuario.nome, banco[i].numero, banco[i].saldo);
	}
}

void inserirEmMassa(conta* banco, int* tamanho, FILE* arq, int limite){
    for (int i=0; i<limite; i++) banco = inserir(banco, tamanho, arq);
}

void copiarPara(conta* destino, conta* origem){
    //destino = (conta*)malloc(sizeof(conta));
    //destino->usuario = (cliente*) malloc (sizeof(cliente));
    strcpy(destino->numero, origem->numero);
    strcpy(destino->usuario.email,origem->usuario.email);
    strcpy(destino->usuario.nome, origem->usuario.nome);
    strcpy(destino->usuario.numero, origem->usuario.numero);
    destino->saldo = origem->saldo;
}

int particao(conta* banco, int ini, int fim) {
	int i, f;
	conta* aux, * pivo;
	aux = (conta*) malloc(sizeof(struct Conta));
	pivo = (conta*) malloc(sizeof(struct Conta));

	if (ini < fim) {
        copiarPara(pivo, &banco[fim]);
        copiarPara(aux, &banco[ini]);
        i = ini+1;
        f = fim-1;

        if ( strcmp(pivo->usuario.nome, aux->usuario.nome)<0 ){
            copiarPara(&banco[ini], pivo);
            copiarPara(&banco[fim], aux);
            particao(banco,i,fim);
        }
        return particao(banco,ini,f);
	}

}

void quickSort(conta* banco, int ini, int fim ) {

	int posPivo;

	if ( ini < fim ) {
		posPivo = particao(banco,ini,fim);
		quickSort(banco, ini, posPivo - 1 );
		quickSort(banco, posPivo + 1, fim );
	}

}

void insertionSortAdaptado(conta* banco, int tamanho, int ini, int h ) {
	int i, j;
	conta* aux;
	aux = (conta*) malloc(sizeof(struct Conta));

	for (i=ini+h; i < tamanho; i++) {
        copiarPara(aux, &banco[i]);
		j = i - h;

		while  (  ( j >= 0 ) && ( strcmp(banco[j].usuario.nome, aux->usuario.nome)> 0 ) ) {
			// TROCAR
			copiarPara(&banco[j+h], &banco[j]);
			j = j - h;
		}
		copiarPara(&banco[j+h], aux);
	}
}

void shellSort(conta* banco, int tamanho) {

    int i, h;

    // GERAR o MAIOR H
    for(h=1; h <= tamanho; h = 3*h+1){
    }

    for (h = (h - 1)/3; h >= 1; h = (h - 1)/3) {
        for (i=0; i < h; i++) {
            insertionSortAdaptado(banco, tamanho, i, h );
        }
    }
}

int menu() {
	int op;
	system("@cls||clear");  // LIMPA A TELA
	printf("\n\nSISTEMA BANCÁRIO\n\n");
	printf("1 - Inserir\n");
	printf("2 - Pesquisar por número\n");
	printf("3 - Pesquisar por nome\n");
	printf("4 - Aumentar\n");
	printf("5 - Diminuir\n");
	printf("6 - Excluir\n");
	printf("7 - Listar\n");
	printf("8 - Quick Sort\n");
	printf("9 - Shell Sort\n");
	printf("10 - Inserir em Massa\n");
	printf("0 - Sair\n");
	do {
		printf("Escolha sua opção: ");
		scanf(" %d", &op);
		limparBuffer();
	} while(op < 0 || op > 10);
	return op;
}

int main() {
	printf("A localidade corrente agora é %s \n", setlocale(LC_ALL,""));
	printf("\nAperte Qualquer Tecla...");
    getchar();

    FILE *arq;
    if ((arq=fopen ("contas.txt","r"))==NULL){
        printf ("Erro na abertura do arquivo.");
        return 0;
    }

	int op, tamanho=0;
	conta* santoAndre=NULL;
	do {
		op = menu();
		switch ( op ) {
			case 0:
				// SAIR. NÃO PRECISA FAZER NADA
				break;
			case 1:
				//INSERIR CONTA
			    santoAndre = inserir(santoAndre, &tamanho, arq);
				break;
			case 2:
				//PESQUISA POR CONTA
				pesquisarConta(santoAndre, tamanho);
				break;
			case 3:
				//PESQUISA POR NOME
				pesquisarNome(santoAndre, tamanho);
				break;
			case 4:
				//DEPOSITAR
				depositar(santoAndre, tamanho);
				break;
			case 5:
				//SACAR
				sacar(santoAndre, tamanho);
				break;
			case 6: ; // label statement
				//EXCLUIR
                char ex[10];
				printf("\nEntre o número da Conta: ");
                scanf(" %s", ex);
                limparBuffer();
				excluir(santoAndre, &tamanho, ex);
				break;
			case 7:
				//LISTAR
				listar(santoAndre, &tamanho);
				break;
            case 8:
                //INSERT SORT
                quickSort(santoAndre, 0, tamanho-1);
                break;
            case 9:
                //SHELL SORT
                shellSort(santoAndre, tamanho);
                break;
            case 10:
                //INSERIR EM MASSA (MAL FUNCIONAMENTO)
                if (santoAndre==NULL){
                    printf("\nMétodo não disponível para Bancos Vazios.\n");
                    break;
                }
                printf("\nQuantos usuários quer inserir a partir de arquivo?\n");
                int qnt;
                scanf("%d", &qnt);
                inserirEmMassa(santoAndre, &tamanho, arq, qnt);
                break;
			default:
				printf ("\n\nOpção inválida!\n\n");
				break;
		}
		printf("\nAperte Qualquer Tecla...");
		getchar();
	} while (op != 0);
	fclose(arq);
	return 0;
}
