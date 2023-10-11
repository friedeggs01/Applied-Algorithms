#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
node *createNode(int x){
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}
void printList(node *l){
    node *p = l;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}
node *addElement(node *p, int x){
    node *temp = createNode(x);
    p->next = temp;
    return temp;
}
node *deleteHead(node *l){
    node *p = l;
    p = p->next;
    delete(l);
    return p;
}
node *deleteTail(node *l){
    node *p = l;
    while(p->next->next != NULL){
        p = p->next;
    }
    delete(p->next);
    p->next = NULL;
    return l;
}
node *deleteAt(node *l, int k){
    node *p = l;
    for(int i = 0; i < k-1; i++){
        p = p->next;
    }
    node *temp = p->next;
    p->next = p->next->next;
    delete(temp);
    return l;
}
int main() {
    int n, k, x;
    cin >> n >> x;
    node *l = createNode(x);
    node *p = l;
    for(int i = 1; i < n; i++){
        cin >> x;
        p = addElement(p, x);
    }
    cin >> k;
    if(k == 0){
        l = deleteHead(l);
    } else if(k == n) {
        l = deleteTail(l);
    } else {
        l = deleteAt(l, k);
    }
    printList(l);
}