// Tarjan

// num[v] số thứ tự đỉnh v được thăm bởi DFS
// low[v] num nhỏ nhất của đỉnh x nào đó mà tồn tại cạnh ngược (u, x) 
// mà ở đó u là con cháu của v


#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
int cnt = 0;
int t=0;
int num[100001];
int low[100001];
stack<int> s; // chứa tất cả các đỉnh trong một đồ thị liên thông
bool inStack[100001];

void DFS(int u) {
    t = t+1;
    num[u] = t;
    low[u] = t;
    s.push(u);
    inStack[u] = true;
    for (const int& v : adj[u]) { // explore adjacent nodes of u
        if(num[v] > 0) {
            if(inStack[v]) {
                low[u] = min(low[u], num[v]);
            }
        } else {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == num[u]){
        cnt++;
        while(true  && !s.empty()){
            int x = s.top(); s.pop();
            inStack[x] = false;
            if(x==u) break;
        }
    }
}


int main() {
    freopen("5.txt", "r", stdin);
    scanf("%d%d", &n, &m);

    adj.resize(n + 1);

    int u, v;
    while (m--) {
        scanf("%d%d", &u, &v);
        // adj[v].push_back(u); not using because directed graph
        adj[u].push_back(v);
    }

    for(int v=1; v<=n; v++) {
        num[v] = 0; low[v] = 0; inStack[v] = false;
    }
    for(int i=1; i<=n; i++){
        if(num[i]==0) DFS(i);
    }
    cout << cnt;
    return 0;
}