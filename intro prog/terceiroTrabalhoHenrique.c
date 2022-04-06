#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

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
conta* criarConta(conta* banco, int* tam){
	printf("\nEntre com os dados no Cliente\nNome: ");
	scanf(" %s", banco[(*tam)].usuario.nome);
	limparBuffer();

	printf("\nTelefone: ");
	scanf(" %s", banco[(*tam)].usuario.numero);
	limparBuffer();

	printf("\nEmail: ");
	scanf(" %s", banco[(*tam)].usuario.email);
	limparBuffer();

	do{
		printf("\nNúmero da Conta: ");
		scanf(" %s", banco[(*tam)].numero);
	}while(posicaoConta(banco, banco[(*tam)].numero, ((*tam)+1)));
	limparBuffer();
	banco[(*tam)].saldo = 0;

	(*tam)++;

	return banco;
}

conta* inserir(conta* banco, int* tamanho){
	if((*tamanho)%10){
	   banco = criarConta(banco, tamanho);
    }else{
        banco = (conta*)realloc(banco, (*tamanho+10)*sizeof(struct Conta));
        banco = criarConta(banco, tamanho);
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
    toupper(numero);
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
	toupper(conta);
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
		return 0;
	}

	printf("\nEntre o valor a ser sacado: ");
	scanf("%f", &valor);
	limparBuffer();
	toupper(conta);

    if(banco[x].saldo >= valor){
		banco[x].saldo -= valor;
	}else{
		printf("Valor Insuficiente!");
	}
}
// Excluir uma conta: pedir o número da conta e excluir do vetor.
void excluir(conta* banco, int* tamanho){
	char numero[15];

	printf("\nEntre o número da Conta: ");
	scanf(" %s", numero);
	limparBuffer();

	toupper(numero);

    int x = posicaoConta(banco, numero, *tamanho);

    if((*tamanho)==1){
    	free(banco);
		banco = NULL;
	}else if(!((*tamanho)%10)){
		limparConta(banco, x, *tamanho);
    }else{
    	banco = (conta*)realloc(banco, (*tamanho-10)*sizeof(struct Conta));
        banco = criarConta(banco, tamanho);
	}
	(*tamanho)--;
}
// Listar: mostrar todas as contas e seu respectivo saldo.
void listar(conta* banco, int tamanho){
	int i;

	if(tamanho == 0) printf("\nNão há Clientes no momento");

	for ( i=0; i<tamanho; i++){
		printf("\nCliente: %s \nConta: %s \tSaldo: %f", banco[i].usuario.nome, banco[i].numero, banco[i].saldo);
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
	printf("0 - Sair\n");
	do {
		printf("Escolha sua opção: ");
		scanf(" %d", &op);
		limparBuffer();
	} while(op < 0 || op > 7);
	return op;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
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
			    santoAndre = inserir(santoAndre, &tamanho);
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
			case 6:
				//EXCLUIR
				excluir(santoAndre, &tamanho);
				break;
			case 7:
				//LISTAR
				listar(santoAndre, tamanho);
				break;
			default:
				printf ("\n\nOpção inválida!\n\n");
				break;
		}
		printf("\nAperte Qualquer Tecla...");
		getchar();
	} while (op != 0);
	return 0;
}
