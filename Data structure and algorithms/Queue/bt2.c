#include<stdio.h>
#include<

typedef int datatype;
tydedef struct _node{
    datatype element;
    struct _node
}

int isempty(queue *q) {
    if(q==NULL) return 1;
    if((q->front==NULL)&&(q->back==NULL)) return 1;
    return 0;
}
int enqueue(datatype X, queue *q){
    if(q==NULL) return 0;
    if(isempty(q)){
        Node *p=makenewnode(X);
        q->back = p;
        q->front = p;
        return 1;
    }
}
int main()