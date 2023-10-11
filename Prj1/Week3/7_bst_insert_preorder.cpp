#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

bool check(node* t, int x) {
    if (t == NULL)
        return false;  // Base case: Reached the end of the tree without finding a match

    if (x == t->data)
        return true;  // Found a match for x

    if (x < t->data)
        return check(t->left, x);  // Search in the left subtree if x is less than current node's value
    else
        return check(t->right, x);  // Search in the right subtree if x is greater than or equal to current node's value
}

node *insertBST(node *t, int x){
    if(check(t, x)) {
        return t;
    }
    if(t == NULL){
        node *temp = new node;
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    } else {
        if(x < t->data){
            t->left = insertBST(t->left, x);
        } else {
            t->right = insertBST(t->right, x);
        }
        return t;
    }
}

void printBST(node *t){
    if(t != NULL){
        cout << t->data << " ";
        printBST(t->left);
        printBST(t->right);
    }
}
int main() {
    // freopen("7.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie();
    node *t = NULL;
    while(true) {
        string temp;
        cin >> temp;
        if(temp == "#") {
            break;
        } else if(temp == "insert") {
            int k; cin >> k;
            t = insertBST(t, k);
        }
    }
    printBST(t);
}