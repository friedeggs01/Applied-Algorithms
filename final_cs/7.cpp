#include<bits/stdc++.h>
using namespace std;

int n, m;
map<int, list<int>> adj;
map<int, bool> visited;
queue<int> q;
int cnt = 0;

int count_worker() {
    priority_queue<pair<int, int>> pq;

    for (int i = 1; i <= n; i++) {
        pq.push(make_pair(adj[i].size(), i));
    }
    
    while (!pq.empty()) {
        int node = pq.top().second;
        cout << node << endl;
        pq.pop();

        if (!visited[node]) {
            visited[node] = true;
            cnt++;

            for (auto adjacent : adj[node]) {
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    pq.push(make_pair(-adj[adjacent].size(), adjacent));
                }
            }
        }
    }

    return cnt;
}
int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("7.txt", "r", stdin);
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
    cout << count_worker();
}