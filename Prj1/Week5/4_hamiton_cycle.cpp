#include<bits/stdc++.h>
using namespace std;

map<int, set<int>> adj;
int n, m, t;

int solve() {
    for(int i=1; i<=n; i++){
        if(adj[i].size() < (n-1)/2){
            return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("4.txt", "r", stdin);
    cin >> t;
    while(t--){
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
        cout << solve() << endl;
    }
}