#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	int value;
	struct _Node = *next;
}Node;
//Tạo node mới
Node* makenewnode(int x){
	Node *p = NULL;
	p = (Node*)malloc(sizeof(Node));
	if(p==NULL){
		printf("Error in mem alloc\n");
		exit(0);
	}
	p->value = x;
	p->next = NULL;

	return p;
}
// In ra hết list
void printList(Node* h){
	Node* p = h;
	while(p!=NULL){
		printf("%d ", p->value);
		p = p->next;
	}
}
// Giải phóng list
void freeList(Node* h){
	Node *tmp, *p=h;

	while(p!=NULL){
		tmp=p->next;
		free(p);
		p=tmp;
	}
}
//Tìm node cuối cùng
Node* findLast(Node* h){
	Node *p=h;
	while(p!=NULL){
		if(p->next==NULL) return p;
		p=p->next;
	}
	return NULL;
}
//Tìm node đầu tiên có giá trị x
Node* locate(Node* h, int x){
	Node* p = h;

	while(p!=NULL){
		if(p->value==x) return p;
		p=p->next;
	}

	return NULL;
}
//Tìm node trước node p
Node* prev(Node* h, Node* p){
	Node* q = h;
	while(q!=NULL){
		if(q->next==p) return q;
		q=q->next;
	}
	return NULL;
}
//Chèn giá trị x vào phần tử p trên list
Node* insertAfter(Node* h, Node* p, int x){
	if((p==NULL)&&(h!=NULL)) return h;
	Node* q = makenewnode(x);
	if(h==NULL) return q;
	q->next= p->next;
	p->next = q;
	return h;
}
//Chèn giá trị x vào cuối list
Node* insertLast(Node* h, int x){
	Node* q = makenewnode(x);
	if(h==NULL) return q;
	Node *p = h;
	while(p->next!=NULL){
		p = p->next;
	}
	p->next = q;
	return h;
}
//Chèn giá trị x vào node p 
Node* insertAt(Node* h, Node*p, int x){
	if((p==NULL)&&(h!=NULL)) return h;
	Node* pp = prev(h, p);
	Node* q = makenewnode(x);
	if(pp==NULL){
		if(h==NULL) return q;
		q
	}
	q->next = p;
	pp->next = q;
	return h;
}
Node* insertAtRecursive(Node*h, Node* p, int x){

}
Node *remove(Node* h, Node* p){
	if(h==NULL || p==NULL) return h;
	if (h==p)
	{
		h = h->next;
		free(p);
		return h;
	} else {
		h->next = remove(h->next, p);
		return h;
	}
	
}
// Tạo danh sách mới, gán từng node của danh sách cũ vào đầu danh sách mới
Node *daods1(Node *h){
	if((h==NULL)||(h->next==NULL)) return h;
	Node *tmp = h, *dsmoi=NULL, *newnode;
	while(tmp!=NULL){
		newnode = makenewnode(tmp->value);
		newnode->next = dsmoi;
		dsmoi = newnode;

		tmp=tmp->next;
	}
	return dsmoi;

}
// Đổi chiều của các pointer next
Node *daods2(Node *h){
	if((h==NULL)||(h->next==NULL)) return h;
	Node *p1=NULL, *p2 = h, *p3=p2->next;
	while(p2!=NULL){	
		p2->next = p1;
		if(p3==NULL) break;
		p1=p2;
		p2=p3;
		p3=p3->next;
	}
	return p2;
}
Node *daods3(Node *h){
	if((h==NULL)||(h->next==NULL)) return h;
	if(h->next->next==NULL){
		h->next->next=h;
		Node *tmp = h->next;
		h->next = NULL;
		return tmp;
	}else{
		Node *dcnutdaumoi = daods3(h->next);
		h->next->next=h;
		h->next=NULL;
		
	}
}
Node* sum(Node* h){

}
int  sumRecursive(Node* h){

}