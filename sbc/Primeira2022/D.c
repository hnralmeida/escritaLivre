#include<stdio.h>
#include<stdlib.h>

typedef struct printer Tprinter;

typedef struct printer{
	Tprinter *next;
	int n;	
}Tprinter;

void printerAdd(Tprinter* z, int n){
	Tprinter* aux = z;
	
	if(z==NULL){
		z->n = n;
	}else{
		Tprinter* newT = malloc(sizeof(Tprinter));
		newT->n = n;
		newT->next = NULL;
		
		while(aux->next!=NULL){
			aux = aux->next;
		}
		
		aux->next = newT;		
	}

}

Tprinter *initPrinter(){
	Tprinter *p = malloc(sizeof(Tprinter*));
	p->next = NULL;
	return p;
}

void printP(Tprinter* p){
	Tprinter* aux = p;
	aux=aux->next;
	while(aux->next!=NULL){
		printf("%d\n", aux->n);
		aux=aux->next;
	}
	printf("%d", aux->n);
}

void main(){
	int N, i;
	scanf("%d", &N);
	Tprinter *p = initPrinter();
	
    while (N != 0) {
        int Y[N];
        for (i=0; i < N; i++) scanf("%d", &Y[i]);
        for (i=0; i < N; i++) printerAdd(p, Y[N-1-i]);
        printerAdd(p, 0);
        scanf("%d", &N);
    }
    printP(p);
}
