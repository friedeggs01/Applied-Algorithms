#include <bits/stdc++.h>
using namespace std;

struct node{
    string name;
    int gen = 0;
    int des = 0;
    node* dad;
    vector<node*> children;
};

set<node*> everyone; 

node* makenewPerson(string newname){
    node *temp = new node();
    temp->name = newname;
    return temp;
}

void insert(string childName, string dadName){
    node *childnode = NULL, *dadnode = NULL;

     // find if child or dad was existed before
    for(auto i : everyone) {
        if (i->name == dadName) dadnode = i;
        else if (i->name == childName) childnode = i;   
    }
    if(childnode == NULL) {
        childnode = makenewPerson(childName);
        everyone.insert(childnode);
    }
    if(dadnode == NULL) {
        dadnode = makenewPerson(dadName);
        everyone.insert(dadnode);
    }
    
    dadnode->children.push_back(childnode);
    childnode->dad = dadnode;
    
    // update generation by loop from bottom to top (null) of tree
    dadnode->gen = childnode->gen + 1;
    int temp = dadnode->gen;
    node *dadTemp = dadnode->dad;
    while(dadTemp != NULL){
        dadTemp->gen = temp + 1;
        temp = dadTemp->des;
        dadTemp = dadTemp->dad;
    }
    
    // update descendants
    dadnode->des += childnode->des + 1;
    temp = childnode->des;
    dadTemp = dadnode->dad;
    while(dadTemp != NULL){
        dadTemp->des += temp + 1;
        dadTemp = dadTemp->dad;
    }
}

int main(){
    // freopen("6.txt", "r", stdin);
    while(true){
        string  childName; cin >> childName;
        if(childName == "***") break;
        else{
            string dadName; cin >> dadName;
            insert(childName, dadName);
        }
    }
    while(true){
        string query; cin >> query;
        if(query == "***") break;
        else if(query == "generation"){
            string personName; cin >> personName;
            for(auto it : everyone) {
                if (it->name == personName) cout << it->gen << endl;
            }
        }
        else if (query == "descendants"){
            string personName; cin >> personName;
            for(auto it : everyone) {
                if (it->name == personName) cout << it->des << endl;
            }
        }
    }
    return 0;
}