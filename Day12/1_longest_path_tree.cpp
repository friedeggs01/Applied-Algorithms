#include<bits/stdc++.h>
using namespace std;

int n;
map<int, list<pair<int, int>>> adj;

pair<int, int> BFS(int u) {
    int dis[n + 1];
    memset(dis, -1, sizeof(dis));
    queue<int> q;
    q.push(u);
    dis[u] = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (auto v : adj[t]) {
            if (dis[v.first] == -1) {
                q.push(v.first);
                dis[v.first] = dis[t] + v.second;
            }
        }
    }
    int maxDis = 0;
    int nodeIdx;
    for (int i = 1; i <= n; i++) {
        if (dis[i] > maxDis) {
            maxDis = dis[i];
            nodeIdx = i;
        }
    }
    return make_pair(nodeIdx, maxDis);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    freopen("1.txt", "r", stdin);
    
    cin >> n;
    
    // Initialize adjacency list for each node
    for (int i = 1; i <= n; i++) {
        adj[i] = list<pair<int, int>>();
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    
    pair<int, int> t1 = BFS(1);
    pair<int, int> t2 = BFS(t1.first);
    
    cout << t2.second << endl;
    
    return 0;
}