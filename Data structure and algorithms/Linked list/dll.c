#include "stdio.h"
#include "stdlib.h"

typedef struct _DNode{
	int val;
	struct _DNode* prev;
	struct _DNode* next;
}DNode;

DNode *first=NULL,*last=NULL;

DNode* makeNode(int v){
	DNode* p = (DNode*)malloc(sizeof(DNode));
	if (p==NULL) {
		printf("Error in mem alloc!");
		exit(0);
	}
	p->val = v;
	p->next = NULL;
	p->prev = NULL;
	
	return p;
}

void remove_node(DNode* p) {
	if(p == NULL) return;
	if(first == last && p != first) return;
	
	if(first == last && p == first){
		first = NULL; 
		last = NULL; 
		free(p);
		return;
	}
	
	if(p == first){
		first = p->next; 
		first->prev = NULL;
		free(p); 
		return;
	}
	
	if(p == last){
		last = p->prev; 
		last->next = NULL;
		free(p); 
		return;
	}
	
	p->prev->next = p->next;
	p->next->prev = p->prev;
	
	free(p);
}


void insertLast(int x){
	DNode* q = makeNode(x);

	if(first == NULL && last == NULL){
		first = q;
		last = q;
		return;
	}
	
	q->prev = last;
	last->next = q;
	last = q;
}


int sum(DNode *p){
	int s=0;
	if (p==NULL) return s;
	
	DNode *tmp = p;
	while(tmp!=NULL){
		s += tmp->val;
		tmp=tmp->next;
	}
	
	tmp = p;
	while(tmp!=NULL){
		s += tmp->val;
		tmp=tmp->prev;
	}
	
	s -= p->val;
	
	return s;
}


void traverse(){
	DNode *p=first;
	printf("\n");
	while(p!=NULL){
		printf("%d ",p->val);
		p=p->next;
	}
}

int main(){
	DNode *tmp=makeNode(5);
	first = tmp;
	last = tmp;
	
	tmp=makeNode(3);
	first->next=tmp;
	tmp->prev=first;
	last=tmp;
	
	insertLast(4);
	traverse();
	printf("\nsum=%d\n",sum(first->next));
	
	remove_node(first->next);
	traverse();
	
	
	
	return 1;
}
