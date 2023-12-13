// Tìm tập con các đỉnh có tổng trọng số MAX
// 2 đỉnh kề nhau không cùng được chọn
// s1[i] bài toán con cho gốc i, chọn i = sum(s0[j]) + w[i]
// s0[i] bài toán con gốc i, không chọn i = sum(s[j])
// s[i] bài toán con trên cây gốc i = max(s0[i], s1[i])

#include <bits/stdc++.h>
using namespace std;
#define N 100001

int n;
vector<int> A[N]; // A[v] is the list of adjacent nodes to v
vector<int> C[N]; // C[v] is the children of v by DFS
int w[N]; // w[v] is the weight of node v
int p[N]; // p[v] is the parent of v on rooted tree
bool visited[N];
int root; // the specified root of tree, by DFS
int d[N]; // d[v] is the number of children of v, changed during the processing
int s1[N], s0[N], s[N];
int ans;

int cs(int u);
int cs0(int u);
int cs1(int u);

void dfs(int u) { // duyệt theo chiều sâu trên cây đầu vào để biến thành cây có gốc
    visited[u] = true;
    for(int i=0; i < A[u].size(); i++) {
        int v = A[u][i];
        if(!visited[v]) {
            p[v] = u;
            d[u] += 1;
            C[u].push_back(v);
            dfs(v);
        }
    }
}

int cs0(int u) {
    if(s0[u] >= 0) return s0[u]; // bài toán con đã được giải, chỉ cần return
    s0[u] = 0;
    for(int i=0; i < C[u].size(); i++) {
        int v = C[u][i];
        s0[u] += cs(v);
    }
    return s0[u];
}
int cs1(int u) {
    if(s1[u] >= 0) return s1[u];
    s1[u] = w[u];
    for(int i=0; i<C[u].size(); i++) {
        int v = C[u][i];
        s1[u] += cs0(v);
    }
    return s1[u];
}
int cs(int u) {
    if(s[u]>=0) return s[u];
    s[u] = max(cs0(u), cs1(u));
    return s[u];
}

void solve() {
    root = 3;
    for(int v = 1; v <= n; v++) {
        visited[v] = false;
        p[v] = -1; d[v] = 0; C[v].clear();
    }
    dfs(root);
    for(int v=1; v<=n; v++) {
        s0[v] = -1;
        s1[v] = -1;
        s[v] = -1;
    }
    ans = max(cs0(root), cs1(root));
}

int main() {
    freopen("2.txt", "r", stdin);
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    solve();
    cout << ans;
    return 0;
}