#include <bits/stdc++.h>
using namespace std;

int n, m;
map<int, list<int>> adj;
map<int, bool> visited;

void DFS(int a) {
    visited[a] = true;
    // cout << a << " ";

    for (auto i = adj[a].begin(); i != adj[a].end(); i++) {
        if (!visited[*i]) {
            DFS(*i);
        }
    }
}

int countPairs() {
    int count = 0;

    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            // Skip if u and v are already connected or if they are the same vertex
            if (u >= v)
                continue;

            // Disconnect u and v
            adj[u].remove(v);
            adj[v].remove(u);

            // Reset visited map
            visited.clear();

            int cycles_before = 0;
            for (int i = 1; i <= n; i++) {
                if (!visited[i]) {
                    DFS(i);
                    cycles_before++;
                }
            }

            // Reconnect u and v
            adj[u].push_back(v);
            adj[v].push_back(u);

            // Reset visited map
            visited.clear();

            int cycles_after = 0;
            for (int i = 1; i <= n; i++) {
                if (!visited[i]) {
                    DFS(i);
                    cycles_after++;
                }
            }

            // Check if adding the edge (u, v) creates exactly one more cycle
            if (cycles_after - cycles_before == 1)
                count++;
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    // Initialize adjacency list for each node
    for (int i = 1; i <= n; i++) {
        adj[i] = list<int>();
    }

    int u, v;
    while (m--) {
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    // Count the number of pairs
    int result = countPairs();

    // Print the result
    cout << result << endl;

    return 0;
}