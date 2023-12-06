#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> colorArr;

bool isBipartite() {
    colorArr.resize(n + 1, -1);
    colorArr[1] = 1;

    queue<int> q;
    q.push(1);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (colorArr[neighbor] == -1) {
                colorArr[neighbor] = colorArr[node] + 1;
                q.push(neighbor);
            } else if ((colorArr[neighbor] + colorArr[node]) % 2 == 0) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    adj.resize(n + 1);

    int u, v;
    while (m--) {
        scanf("%d%d", &u, &v);
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    cout << isBipartite();

    return 0;
}