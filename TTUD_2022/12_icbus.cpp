#include<bits/stdc++.h>
using namespace std;

int n, k, c[10001], d[10001];
vector<int> adj[10001];
int weight[5001][5001];

// build graph
void BFS(int u) {
    queue<pair<int, int>> q;
    q.push(make_pair(u, d[u]));
    while(!q.empty()) {
        pair<int, int> x = q.front();
        x.second--;
        q.pop();
        for(auto v: adj[x.first]){
            weight[u][v] = min(weight[u][v], c[u]);
            if(!dd[v] && x.second){
                dd[v] = 1;
                q.push(make_pair(v, x.second));
            }

        }
    }
}

void dijkstra(){
    memset(d,62,sizeof d);
    priority_queue<pair<int,int>>q;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> c[i] >> d[i];
    }
    for(int i=1; i<=k; i++) {
        int town1, town2;
        cin >> town1 >> town2;
        adj[town1].push_back(town2);
        adj[town2].push_back(town1);
    }
}