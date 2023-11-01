#include<bits/stdc++.h>
using namespace std;

int n, m;
map<int, list<pair<int, int>>> adj;

void dijkstra(int s) {
    vector<int> dist(n+1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(auto i : adj[u]){
            int v = i.first;
            int weight = i.second;
            if(dist[v]>dist[u]+weight){
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    for(int i=1; i <= n; i++) {
        if(dist[i] == INT_MAX) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("2.txt", "r", stdin);
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
    for(int s=1; s<=n; s++){
            dijkstra(s);
    }

}