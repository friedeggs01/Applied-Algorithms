#include<bits/stdc++.h>
using namespace std;

int n, m, s, t;
map<int, list<pair<int, int>>> adj;
vector<int> dist(1000001, INT_MAX);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dijkstra() {
    pq.push(make_pair(0, s));
    dist[s] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(auto i: adj[u]){
            int v = i.first;
            int weight = i.second;
            if(dist[v]>dist[u]+weight){
                dist[v] = dist[u]+weight;
                pq.push(make_pair(dist[v], v));
            }
        }
        if(t==u) return dist[t];
    }
    return dist[t];
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("1.txt", "r", stdin);
    cin >> n >> m;

    // Initialize adjacency list for each node
    for (int i = 1; i <= n; i++) {
        adj[i] = list<pair<int, int>>();
    }

    int u, v, w;
    while(m--){
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }
    cin >> s >> t;
    cout << dijkstra();
}