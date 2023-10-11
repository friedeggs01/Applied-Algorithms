#include<iostream>
#include<math.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};
node *insert(node *t, int x){
    if(t == NULL){
        node *temp = new node;
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    } else {
        if(x < t->data){
            t->left = insert(t->left, x);
        } else {
            t->right = insert(t->right, x);
        }
    }
}
int treeLevel(node *t){
    if(t == NULL) return -1;
    return 1 + max(treeLevel(t->left), treeLevel(t->right));
}
bool checkAvl(node *t){
    if(t == NULL) return true;
    if(abs(treeLevel(t->left) - treeLevel(t->right)) > 1) return false;
    return checkAvl(t->left) && checkAvl(t->right);
}
node *turnRight(node *a){
    node *b = a->left;
    node *d = b->right;
    a->left = d;
    b->right = a;
    return b;
}
node *turnLeft(node *a){
    node *b = a->right;
    node *d = b->left;
    a->right = d;
    b->left = a;
    return b;
}
node *updateTreeAvel(node *t){
    if(abs(treeLevel(t->left) - treeLevel(t->right)) > 1){
        if(treeLevel(t->left) > treeLevel(t->right)){
            node *p = t->left;
            if(treeLevel(t->left) >= treeLevel(t->right)){
                t = turnRight(t);
            } else {
                t->left = turnLeft(t->left);
                t = turnRight(t);
            }
        } else {
            node *p = t->right;
            if(treeLevel(p->right) > treeLevel(p->left)){
                t = turnLeft(t);
            } else {
                t->right = turnRight(t->right);
                t = turnLeft(t);
            }
        }
    }
    if(t->left != NULL) t->left = updateTreeAvel(t->left);
    if(t->right != NULL) t->right = updateTreeAvel(t->right);
    return t;
}
int main() {
    int n, x;
    cin >> n;
    node *t = NULL;
    for(int i = 0; i < n; i++){
        cin >> x;
        t = insert(t, x);
    }
    while(!checkAvl(t)){
    t = updateTreeAvel(t);}
    cout << treeLevel(t);
}