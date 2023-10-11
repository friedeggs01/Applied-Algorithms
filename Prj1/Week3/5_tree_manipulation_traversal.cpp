#include<bits/stdc++.h>
using namespace std;

struct _Node {
    int data;
    struct _Node *leftMostChild;
    struct _Node *rightSibling;
}Node;
Node root;
Node *makenewnode(int x) {
    Node *p = (Node*)malloc(sizeof(Node));
    if(p==NULL) {
        cout << "Error in mem alloc\n" << endl;
        return 0;
    }
    p->data = x;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}
void insert(int u, int x){
    Node* parentNode = findNote(root, x);
    if(parentNode != nullptr) {
        TreeNode* childNode = new TreeNode
    }
}

void preOder(Node *r){
    if(r==NULL) return;

    Node *p = r->leftMostChild;
    while(p!=NULL){
        preOder(p);
        p = p->rightSibling;
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
int main() {
    freopen("5.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie();
    while(true) {
        string temp;
        cin >> temp;
        if (temp == "*") {
            break;
        } else if (temp == "MakeRoot") {
            int k; cin >> k;
            root = makenewnode(k);
        } else if (temp == "Insert") {
            int u, v; cin >> u >> v;
            insert(u, v);
        } else if (temp == "PreOrder") {
            preOrder(root);
            cout << endl;
        } else if (temp == "InOrder") {
            inOrder(root);
            cout << endl;
        } else {
            postOrder(root);
            cout << endl;
        }
    }
    return 0;
}