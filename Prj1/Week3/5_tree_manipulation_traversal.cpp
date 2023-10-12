#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *leftMostChild;
    struct Node *rightSibling;
};
Node *root = NULL;
Node *makenewnode(int x) {
    Node *p = new Node;
    if(p==NULL) {
        cout << "Error in mem alloc\n" << endl;
        return nullptr;
    }
    p->data = x;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}
Node *find(Node *r, int v){
    if(r==NULL) return NULL;
    if(r->data==v) return r;

    Node *p = r->leftMostChild;
    while(p!=NULL){
        Node *hv = find(p, v);
        if(hv!=NULL) return hv;
        p = p->rightSibling;
    }
    return NULL;
}
void insert(int u, int x) {
    Node* currentNode = find(root, x);

    if (currentNode != nullptr) {
        // 'x' node found, create a new node with data 'u'
        Node* newNode = makenewnode(u);

        if (currentNode->leftMostChild == nullptr) {
            // If 'x' node has no children, set the new node as the leftmost child
            currentNode->leftMostChild = newNode;
        } else {
            // If 'x' node already has children, find the last sibling and append the new node
            Node* lastSibling = currentNode->leftMostChild;
            while (lastSibling->rightSibling != nullptr) {
                lastSibling = lastSibling->rightSibling;
            }
            lastSibling->rightSibling = newNode;
        }
    } else {
        cout << "Node with data " << x << " not found" << endl;
    }
}

void preOrder(Node *r){
    if(r==NULL) return;
    cout << r->data << " ";
    Node *p = r->leftMostChild;
    while(p!=NULL){
        preOrder(p);
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
    cout << r->data << " ";
}
void inOrder(Node *r){
    if(r == NULL) return;

    Node *p = r->leftMostChild;
    inOrder(p);

    cout << r->data << " ";
    if(p!=NULL) p=p->rightSibling;
    while(p!=NULL){
        inOrder(p);
        p=p->rightSibling;
    }
}
int main() {
    // freopen("5.txt", "r", stdin);
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