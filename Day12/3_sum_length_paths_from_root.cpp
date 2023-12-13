// tìm tâm điểm trên cây

#include<bits/stdc++.h>
using namespace std;

#define N 100001

struct Edge {
    int node;
    int w;

    Edge(int _node, int _w) : node(_node), w(_w) {}
};
int n;
vector<Edge> A[N];
int root;
int d[N]; // d[u] is the sum of weights of path from descendant of u to u
int num[N]; // num[u] is the number of descendant (inclusive) of u
int f[N]; // f[u] is the sum of weight of path from other nodes to u
int p[N]; // p[u] is the parent of u

void dfs1(int u){
    for(int i=0; i<A[u].size(); i++) {
        Edge e = A[u][i];
        int v = e.node; // v is node kề với u
        int w = e.w;
        if(p[v]==0){ // p is not visited
            p[v]=u; // u is parent of v
            dfs1(v);
            d[u] = d[u] + d[v] + num[v]*w; // weights của tất cả con u sẽ bằng weights hiện tại cộng weights con của v cộng thêm với số nút con của v nhân với trọng số cạnh uv
            num[u] += num[v]; // lúc này số con của u cần cộng thêm số con của nút v, lưu ý nút lá có số con bằng 1 là chính nó
        }
    }
}
void solvePhase1(){
    for(int v=1; v<=n; v++) {
        p[v] = 0;
        d[v]=0;
        num[v]=1;
        f[v]=0;
    }
    root = 1;
    p[root] = root;
    dfs1(root); // sau bước này có f[root] = d[root] (mình sẽ thêm bớt từ f_root để tránh việc duyệt nhiều lần từng đỉnh)
}
void dfs2(int u){ // know f[u], compute f[v] forall children v of u
    for(int i=0; i < A[u].size(); i++) {
        Edge e = A[u][i];
        int v = e.node;
        int w = e.w;
        if(p[v] == 0){ // nếu nút v chưa được thăm
            int F = f[u] - (d[v] + w*num[v]); // đoạn này chia làm hai phần, phần F là phần mà không phải con của u, hay nói cách khác (d(v) + w*num[v]) chính là con của u
            f[v] = F + d[v] + w*(n-num[v]); // f(v) sẽ được tính bằng F + phần con...
            p[v] = u;
            dfs2(v);
        }
    }
}
void solvePhase2(){
    for(int v = 1; v <= n; v++) {
        p[v]=0;
    }
    root = 1;
    f[root] = d[root];
    p[root] = root;
    dfs2(root);
}

int main() {
    // freopen("3.txt", "r", stdin);
    cin >> n;
    // Initialize adjacency list for each node
    for (int i = 1; i <= n+1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back(Edge(v, w));
        A[v].push_back(Edge(u, w));
    }
    solvePhase1();
    solvePhase2();
    int ans = 0;
    for(int v=1; v<=n; v++) {
        ans = max(ans, f[v]);
    }
    cout << ans;
    return 0;
}