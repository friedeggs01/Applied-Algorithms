#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

node *createNode(int x) {
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void printList(node *l) {
    node *p = l;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

node *addelement(node *p, int x) {
    node *temp = createNode(x);
    node *h = p;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = temp;
    return h;
}

node *addlast(node *p, int x) {
    node *temp = createNode(x);
    if (p == NULL) {
        return temp;
    }
    node *curr = p;
    while (curr->next != NULL) {
        if (curr->data == x) {
            return p; // Node already exists, no need to add
        }
        curr = curr->next;
    }
    if (curr->data == x) {
        return p; // Node already exists, no need to add
    }
    curr->next = temp;
    return p;
}

node *addfirst(node *p, int x) {
    if (p == NULL || p->data == x) {
        return p; // Node already exists or empty list, no need to add
    }
    node *curr = p;
    while (curr->next != NULL) {
        if (curr->next->data == x) {
            return p; // Node already exists, no need to add
        }
        curr = curr->next;
    }
    node *temp = createNode(x);
    temp->next = p;
    return temp;
}

node *addafter(node *p, int u, int v) {
    node *temp = createNode(u);
    node *curr = p;
    while (curr != NULL) {
        if (curr->data == v) {
            if (curr->next != NULL && curr->next->data == u) {
                return p; // Node u already exists, no need to add
            }
            temp->next = curr->next;
            curr->next = temp;
            break;
        }
        curr = curr->next;
    }
    return p;
}

node *addbefore(node *p, int u, int v) {
    if (p == NULL || p->data == u) {
        return p; // Node u already exists or empty list, no need to add
    }
    node *temp = createNode(u);
    if (p->data == v) {
        temp->next = p;
        return temp;
    }
    node *prev = p;
    node *curr = p->next;
    while (curr != NULL) {
        if (curr->data == v) {
            if (curr->next != NULL && curr->next->data == u) {
                return p; // Node u already exists, no need to add
            }
            prev->next = temp;
            temp->next = curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return p;
}
node *remove(node *p, int k) {
    node *prev = NULL;
    node *curr = p;
    while (curr != NULL) {
        if (curr->data == k) {
            if (prev != NULL) {
                prev->next = curr->next;
            } else {
                p = curr->next;
            }
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return p;
}

node *reverse(node *p) {
    node *prev = NULL;
    node *curr = p;
    node *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main() {
    freopen("8.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a;
    node *p = NULL;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (i == 0) {
            p = createNode(a);
        } else {
            p = addelement(p, a);
        }
    }
    
    while (true) {
        string temp;
        cin >> temp;
        if (temp == "#") {
            break;
        } else if (temp == "addlast") {
            int k;
            cin >> k;
            p = addlast(p, k);
        } else if (temp == "addfirst") {
            int k;
            cin >> k;
            p = addfirst(p, k);
        } else if (temp == "addafter") {
            int u, v;
            cin >> u >> v;
            p = addafter(p, u, v);
        } else if (temp == "addbefore") {
            int u, v;
            cin >> u >> v;
            p = addbefore(p, u, v);
        } else if (temp == "remove") {
            int k;
            cin >> k;
            p = remove(p, k);
        } else if (temp == "reverse") {
            p = reverse(p);
        }
    }

    printList(p);

    return 0;
}