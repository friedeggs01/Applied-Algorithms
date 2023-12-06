#include<bits/stdc++.h>
using namespace std;

int n, m;
map<int, list<int>> adj;
map<int, bool> visited;

void DFS(int a) {
    visited[a] = true;
    cout << a << " ";

    for(auto i = adj[a].begin(); i != adj[a].end(); i++) {
        if(!visited[*i]){
            DFS(*i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cin >> n >> m;

    // Initialize adjacency list for each node
    for (int i = 1; i <= n; i++) {
        adj[i] = list<int>();
    }

    int u, v;
    while(m--){
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    DFS(1);
}