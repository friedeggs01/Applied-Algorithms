#include<bits/stdc++.h>
using namespace std;
#define N 1001
int n, m, sou, des;
int graph[N][N];
int residual_graph[N][N];

bool bfs(int path[]){
    bool visited[N];
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(sou);
    visited[sou] = true;
    path[sou] = -1;

    while(!q.empty()) {
        int j = q.front();
        q.pop();
        // cout << j << endl;
        for(int i = 0; i<n; i++) {
            // cout << visited[i] << "  " << residual_graph[j][i] << endl;
            if (visited[i] == false && residual_graph[j][i] > 0) {
                // cout << i << endl;
                if (i==des) {
                    path[i] = j;
                    return true;
                }
                q.push(i);
                path[i] = j;
                visited[i] = true;
            }
        }
    }
    // for(int i = 0; i<n; i++){
    //     cout << path[i] << " ";
    // }
    return false;
}

int foldFulkerson() {
    int u, v;

    for(u=0; u<n; u++){
        for(v=0; v<n; v++) {
            residual_graph[u][v] = graph[u][v];
        } 
    }


    int path[N];
    int max_flow=0;

    while(bfs(path)){
        int path_flow = INT_MAX;
        for (v=des; v!=sou; v=path[v]) {
            u = path[v];
            path_flow = min(path_flow, residual_graph[u][v]);
            // cout << path_flow;
        }
        for (v=des; v!=sou; v=path[v]) {
            u = path[v];
            residual_graph[u][v] -= path_flow;
            residual_graph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }
    return max_flow;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("3.txt", "r", stdin);
    cin >> n >> m;
    cin >> sou >> des;
    sou--;
    des--;

    // Initialize all weight is zero
    for(int u=0; u<n; u++){
        for(int v=0; v<n; v++) {
            graph[u][v] = 0;
        }
    }
        
    int n1, n2, w;
    while(m--){
        cin >> n1 >> n2 >> w;
        // node start from 0
        graph[n1-1][n2-1] = w;
    }

    cout << foldFulkerson();
    return 0;
}