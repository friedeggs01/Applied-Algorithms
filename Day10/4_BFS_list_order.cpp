#include<bits/stdc++.h>
using namespace std;

int n, m;
map<int, set<int>> adj;
map<int, bool> visited;
queue<int> q;

void BFS() {
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            q.push(i);
            while(!q.empty()) {
                int node = q.front();
                cout << q.front() << " ";
                q.pop();

                for(auto adjacent : adj[node]){
                    if(!visited[adjacent]) {
                        visited[adjacent] = true;
                        q.push(adjacent);
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cin >> n >> m;

    // Initialize adjacency list for each node
    for (int i = 1; i <= n; i++) {
        adj[i] = set<int>();
    }

    int u, v;
    while(m--){
        cin >> u >> v;
        adj[v].insert(u);
        adj[u].insert(v);
    }
    BFS();
}