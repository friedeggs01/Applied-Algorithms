#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, m;
vector<vector<int>> adj;
int cnt = 0;
int t = 0;
int num[100001];
int low[100001];
stack<int> s; // contains all vertices in a strongly connected component
bool inStack[100001];
int ap = 0, bridges = 0;


void DFS(int u, int ps) {
    t++;
    num[u] = t;
    low[u] = t;
    s.push(u);
    inStack[u] = true;
    for (const int& v : adj[u]) { // explore adjacent nodes of u
        if(v==ps) continue; // dont go to back through the same path
        if (num[v] > 0) { // if v was already discovered means that we found an ancestor
            if (inStack[v]) {
                low[u] = min(low[u], num[v]);
            }
        } else {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) {
                bridges++;
                ap++;
            } else if (low[v] == num[u]) {
                ap++;
            }
        }
    }
    if (low[u] == num[u]) {
        cnt++;
        while (!s.empty()) {
            int x = s.top();
            s.pop();
            inStack[x] = false;
            if (x == u) break;
        }
    }
}

int main() {
    freopen("6.txt", "r", stdin);
    scanf("%d%d", &n, &m);

    adj.resize(n + 1);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int v = 1; v <= n; v++) {
        num[v] = 0;
        low[v] = 0;
        inStack[v] = false;
    }
    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) DFS(i, -1);
    }

    cout << ap << " " << bridges;
    return 0;
} 