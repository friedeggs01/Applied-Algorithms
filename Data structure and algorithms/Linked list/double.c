#include<stdio.h>

typedef struct _DNode
{
    int value;
    DNode *prev;
    DNode *next;
}DNode;

DNode *first;
DNode *last;

DNode *makenewNode(int x){
    DNode* p = NULL;
    p->value = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

int main(){

}