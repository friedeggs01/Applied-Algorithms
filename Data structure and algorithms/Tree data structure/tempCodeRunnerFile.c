//Cây tổng quát được biểu diễn bởi con trái và anh em kề cận phải
//Viết hàm để đếm số nút có k (k>=0) con trong cây
#include<stdio.h>
#include<stdlib.h>

typedef char elementtype;
typedef struct _Node{
    elementtype id;
    struct _Node *leftMostChild;
    struct _Node *rightSibling;
}Node;

Node *makenewnode(elementtype x){
    Node *p = (Node*)malloc(sizeof(Node));
    if(p==NULL){
        printf("Error in mem alloc\n");
        exit(0);
    }
    p->id = x;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}
void preOder(Node *r){
    if(r==NULL) return;

    Node *p = r->leftMostChild;
    while(p!=NULL){
        preOder(p);
        p = p->rightSibling;
    }
}
int countChild(Node *r){
    int child = 0;
    Node *p = r->leftMostChild;
    while(p->rightSibling != NULL){
        child++;
        p = p->rightSibling;
    }
    return child;
}
int count = 0;
void count_node_contain_k_child(Node *r, int k){
    if(r==NULL) return;
    if(k<0) return;
    //printf("aaa\n");
    Node *p = r;
    if(countChild(p)==k) count++;
    printf("%c\n", r->id);
    p = p->leftMostChild;
    while(p!=NULL){
        count_node_contain_k_child(p, k);
        p = p->rightSibling;
    }
    return;
}

int main(){
    Node *root=NULL;
	Node *nutA, *nutB, *nutC, *nutD, *nutE, *nutF, *nutG, *nutH, *nutI, *nutJ, *nutK;
	nutA = makenewnode('A');
	nutB = makenewnode('B');
	nutC = makenewnode('C');
	nutD = makenewnode('D');
	nutE = makenewnode('E');
	nutF = makenewnode('F');
	nutG = makenewnode('G');
	nutH = makenewnode('H');
	nutI = makenewnode('I');
	nutJ = makenewnode('J');
	nutK = makenewnode('K');
	
	nutA->leftMostChild = nutB;
	
	nutB->leftMostChild = nutE;
	nutB->rightSibling = nutC;
	
	nutC->leftMostChild = nutG;
	nutC->rightSibling = nutD;
	
	nutE->rightSibling = nutF;
	
	nutG->leftMostChild = nutH;
	
	nutH->rightSibling = nutI;
	nutI->rightSibling = nutJ;
	nutJ->rightSibling = nutK;
	
	root = nutA;


    count_node_contain_k_child(root, 2);
    printf("%d\n", count);
}