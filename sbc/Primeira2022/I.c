#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList TLinkedList;

typedef struct LinkedList{
	TLinkedList *next;
	long long int n;	
}TLinkedList;

TLinkedList *initLinkedList(){
	TLinkedList *p = malloc(sizeof(TLinkedList*));
	p->next = NULL;
	return p;
}

void ListAdd(TLinkedList* z, long long int n){
	TLinkedList* aux = z;

	TLinkedList* newT = malloc(sizeof(TLinkedList));
	newT->n = n;
	newT->next = NULL;
	
	while(aux->next!=NULL){
		aux = aux->next;
	}	
	aux->next = newT;		

}

void printP(TLinkedList* p){
	TLinkedList* aux = p;
	aux=aux->next;
	
	while(aux->next!=NULL){
		if(aux->n==1) printf("SIM\n");
		else printf("NAO\n");
		aux=aux->next;
	}
	if(aux->n==1) printf("SIM");
	else printf("NAO");
}

void main(){
	long long int n=1, half, i, sum=0, j;
	int flag=0;
	TLinkedList *p = initLinkedList();
	TLinkedList *num = initLinkedList();
	while(n!=0){
		scanf("%lld", &n);
		if(n!=0) ListAdd(num, n);
	}
	
	TLinkedList *aux = num->next;
	
	while(aux!=NULL){
		half = aux->n/2+1;
		
		for(i=0; i<half; i++){
			long long int cap = (((half-i)+1)*(half-i)/2);
			if(cap<aux->n) {
				//printf("\ncap");
				break;
			}
			for(j=0; j<half; j++){
				//printf("\n- %lld< %lld", sum, aux->n);
				if(sum<aux->n && (half-i-j)>0){
					sum=sum+half-i-j;
				}else break;
			}
			if(sum==aux->n){
				flag=1;
				break;
			}
			else sum=0;
		}
		if(flag==1) ListAdd(p, 1);
		else ListAdd(p, 0);
		flag=0;
		aux = aux->next;
	}
	//printf("\npre print:");
	//scanf("%lld", &n);
	printP(p);
}
