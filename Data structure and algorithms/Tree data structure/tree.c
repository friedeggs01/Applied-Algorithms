#include<stdio.h>

typedef char elementtype;
typedef struct _Node{
    elementtype id;
    struct _Node *leftMostChild;
    struct _Node *rightSibling;
}Node;



Node *makenewnode(elementtype X){
    Node *p = (Node*)malloc(sizeof(Node));
    if(p==NULL) {
        printf("Error in mem alloc\n");
        exit(0);
    }
    p->id = X;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

void preOrder(Node *r){
    if(r==NULL) return;

    printf("%c ", r->id);

    Node *p = r->leftMostChild;
    while(p!=NULL){
        preOrder(p);
        p=p->rightSibling;
    }
}
void postOrder(Node *r){
    if(r == NULL) return;

    Node *p = r->leftMostChild;
    while(p!=NULL){
        postOrder(p);
        p=p->rightSibling;
    }
    printf("%c ", r->id);
}
void inOrder(Node *r){
    if(r == NULL) return;

    Node *p = r->leftMostChild;
    inOrder(p);

    printf("%c ", r->id);
    if(p!=NULL) p=p->rightSibling;
    while(p!=NULL){
        inOrder(p);
        p=p->rightSibling;
    }
}
Node *find(Node *r, elementtype v){
    if(r==NULL) return NULL;
    if(r->id==v) return r;

    Node *p = r->leftMostChild;
    while(p!=NULL){
        Node *hv = find(p, v);
        if(hv!=NULL) return hv;
        p = p->rightSibling;
    }
    return NULL;
}

int count(Node *r){
    if(r == NULL) return 0;

    int c = 1;
    Node *p = r->leftMostChild;
    while(p!=NULL){
        c +=count(p);
        p = p->rightSibling;
    }

    return c;
}
int countleaves(Node *r){
    if(r == NULL) return 0;

    Node *p = r->leftMostChild;
    if(p==NULL) return 1;

    int c=0;
    while(p!=NULL){
        c +=countleaves(p);
        p=p->rightSibling;
    }
    return c;
}
int main(){
    treeNode *root = NULL;
    treeNode *nutA, *nutB, *nutC, *nutD, *nutE, *nutF, *nutG, *nutH, *nutI, *nutJ, *nutK;
    
}
