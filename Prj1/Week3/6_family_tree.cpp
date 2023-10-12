#include <iostream>
#include <map>
#include <string>
using namespace std;

struct node {
    int data;
    node* dad;
};

map<string, node*> familyTree;

// Function to count the descendants of a given name
int countDescendants(const string& name) {
    int descendants = 0;
    node* current = familyTree[name];

    if (current == nullptr) {
        return descendants;
    }

    for (const auto& entry : familyTree) {
        if (entry.second->dad == current) {
            descendants++;
            descendants += countDescendants(entry.first);
        }
    }

    return descendants;
}

// Function to count the generations of the descendants of a given name
int countGenerations(const string& name) {
    int generations = 0;
    node* current = familyTree[name];

    if (current == nullptr) {
        return generations;
    }

    for (const auto& entry : familyTree) {
        if (entry.second->dad == current) {
            generations = max(generations, 1 + countGenerations(entry.first));
        }
    }

    return generations;
}

// Function to insert a child-parent relationship into the family tree
void insert(const string& child, const string& dad) {
    node* childNode = new node;
    childNode->data = stoi(child);
    childNode->dad = familyTree[dad];
    familyTree[child] = childNode;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("6.txt", "r", stdin);
    while (true) {
        string temp;
        cin >> temp;

        if (temp == "***") {
            break;
        } else if (temp == "descendants") {
            string t;
            cin >> t;
            int numDescendants = countDescendants(t);
            cout << numDescendants << endl;
        } else if (temp == "generation") {
            string t;
            cin >> t;
            int numGenerations = countGenerations(t);
            cout << numGenerations << endl;
        } else {
            string child, dad;
            cin >> child >> dad;
            insert(child, dad);
        }
    }

    return 0;
}