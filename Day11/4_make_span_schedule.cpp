#include<bits/stdc++.h>
using namespace std;

int n, m, d[10001];
// topology sorting

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("4.txt", "r", stdin);
    cin >> n >> m;
    vector<int> d(n+1);
    for(int i=1; i<=n; i++) {
        cin >> d[i];
    }
    
    vector<vector<int>> adj(n + 1);
    vector<int> inDegree(n + 1, 0); // số bậc vào của một đỉnh

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++; 
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> earliestCompletionTime(n + 1, 0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            earliestCompletionTime[v] = max(earliestCompletionTime[v], earliestCompletionTime[u] + d[u]);
            inDegree[v]--;

            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    int maxCompletionTime = 0;
    for (int i = 1; i <= n; i++) {
        // find the last completed task
        maxCompletionTime = max(maxCompletionTime, earliestCompletionTime[i] + d[i]);
    }

    cout << maxCompletionTime << endl;

    return 0;
}