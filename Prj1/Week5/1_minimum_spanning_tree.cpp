#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, c;
    edge(int _u, int _v, int _c): u(_u), v(_v), c(_c) {};
};

struct kruskal {
    vector<int> p;

    void init(int n) {
        p.resize(n + 5, 0);
        for (int i = 1; i <= n; i++) p[i] = i;
    }

    int find(int u) {
        if (p[u] == u) return u;
        return p[u] = find(p[u]);
    }

    bool join(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        p[v] = u;
        return true;
    }
}kruskal;

int n, m, ans = 0;
vector <edge> edges;

int main() {
    freopen("1.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
    }

    kruskal.init(n);

    sort(edges.begin(), edges.end(), [](edge & x, edge & y) {
        return x.c < y.c;
    });

    for (auto e : edges) {
        if (!kruskal.join(e.u, e.v)) continue;
        ans += e.c;
    }
    cout << ans;
}