//chuyển về đồ thị chi phí rồi tìm shortest path

#include <bits/stdc++.h>
using namespace std;
 
int n,m;
int c[5001],d[5001],dd[5001];
vector <int> adj[5001];
int weight[5001][5001];
 
// xây dựng đồ thị trọng số
void BFS(int u){
    queue<pair<int,int>> q;
    q.push(make_pair(u,d[u]));
    while(!q.empty()){
        pair<int,int> x = q.front();
        x.second--;
        q.pop();
        for(auto v: adj[x.first]){
            weight[u][v] = min(weight[u][v],c[u]);
            if(!dd[v] && x.second){
                dd[v] = 1;
                q.push(make_pair(v,x.second));
            }
        }
    }
}
 
// duyệt tìm đường đi ngắn nhất
void dijkstra(){
    memset(d,62,sizeof d);
    priority_queue<pair<int,int>>q;
    d[1] = 0;
    q.push(make_pair(d[1],1));
    while(!q.empty()){
        int u = q.top().second;
        int w = q.top().first;
        q.pop();
        if(w != d[u]) continue;
        if(u == n) return;
        for(int i = 1; i <= n; ++i){
            int v = i;
            int l = weight[u][v];
            if(w+l < d[v]){
                d[v] = w+l;
                q.push(make_pair(d[v],v));
            }
        }
    }
}
 
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("5.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> c[i] >> d[i];
    }
    for(int i = 1; i <= m; ++i){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(weight,62,sizeof weight);
    for(int i = 1; i <= n; ++i){
        BFS(i);
    }
    dijkstra();
    cout << d[n];
    return 0;
}