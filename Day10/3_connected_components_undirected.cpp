#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
int cnt = 0;

void DFS(int u) {
    visited[u] = true;
    for (const int& v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

void global_DFS() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ++cnt;
            DFS(i);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    int u, v;
    while (m--) {
        scanf("%d%d", &u, &v);
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    global_DFS();
    cout << cnt;
    return 0;
}