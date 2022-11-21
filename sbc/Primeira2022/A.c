#include<stdlib.h>
#include<stdio.h>

typedef struct LinkedList TLinkedList;

typedef struct LinkedList{
	TLinkedList *next;
	int n;	
}TLinkedList;

void LinkedListAdd(TLinkedList* z, int n){
	TLinkedList* aux = z;
	
	TLinkedList* newT = malloc(sizeof(TLinkedList));
	newT->n = n;
	newT->next = NULL;
	
	while(aux->next!=NULL){
		aux = aux->next;
	}
	
	aux->next = newT;		

}

TLinkedList *initLinkedList(){
	TLinkedList *p = malloc(sizeof(TLinkedList*));
	p->n=0;
	p->next = NULL;
	return p;
}

void printList(TLinkedList* p){
	TLinkedList* aux = p;
	aux=aux->next;
	while(aux->next!=NULL){
		printf("%d\n", aux->n);
		aux=aux->next;
	}
	printf("%d", aux->n);
}

void main(){
	int qt, x;
    int i;
    TLinkedList *p = initLinkedList();
	
    do {
    	scanf("%d %d", &qt, &x);
        if(qt==0){
        	break;
		}else{
        	int vetor[qt-2];

	        vetor[x-1] = 1;
	
	        for (i = 0; i < qt - 2; i++) {
	            scanf("%d", &x);
	            vetor[x-1] = 1;
	        }
	
	        for (i = 0; i < qt; i++) {
	            if (vetor[i] != 1) {
	                LinkedListAdd(p, (i+1));
	                printf("%d\n", i+1);
	           	}
	    	}
    	}
    } while (qt != 0);
    
    //printList(p);

}
