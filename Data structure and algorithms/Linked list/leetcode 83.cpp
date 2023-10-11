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
node *addElement(node *p, int x){
    node *temp = createNode(x);
    p->next = temp;
    return temp;
}
void printList(node *l){
    node *p = l;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}
node *remove_duplicates(node *l){
    node *p = l;
    while(p->next != NULL){
        if(p->data == p->next->data){
            p->next = p->next->next;
        } else {
            p = p->next;
        }
    }
    return l;
}
int main(){
    int n, x;
    cin >> n >> x;
    node *l = createNode(x);
    node *p = l;
    for(int i = 1; i < n; i++){
        cin >> x;
        p = addElement(p, x);
    }
    remove_duplicates(l);
    printList(l);
}