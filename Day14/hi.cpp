#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int max_val;
};

void buildTree(vector<int>& a, vector<Node>& tree, int start, int end, int pos) {
    if (start == end) {
        tree[pos].max_val = a[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(a, tree, start, mid, 2 * pos + 1);
    buildTree(a, tree, mid + 1, end, 2 * pos + 2);
    tree[pos].max_val = max(tree[2 * pos + 1].max_val, tree[2 * pos + 2].max_val);
}

int query(vector<Node>& tree, int start, int end, int pos, int left, int right) {
    if (left > end || right < start) {
        return 0; 
    }
    if (left <= start && right >= end) {
        return tree[pos].max_val; 
    }
    int mid = (start + end) / 2;
    return max(query(tree, start, mid, 2 * pos + 1, left, right),
               query(tree, mid + 1, end, 2 * pos + 2, left, right));
}

void update(vector<Node>& tree, int start, int end, int pos, int index, int value) {
    if (start == end) {
        tree[pos].max_val = value;
        return;
    }
    int mid = (start + end) / 2;
    if (index <= mid) {
        update(tree, start, mid, 2 * pos + 1, index, value);
    } else {
        update(tree, mid + 1, end, 2 * pos + 2, index, value);
    }
    tree[pos].max_val = max(tree[2 * pos + 1].max_val, tree[2 * pos + 2].max_val);
}

int main() {
    freopen("5.txt", "r", stdin);
    int n, m;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<Node> tree(4 * n);
    buildTree(a, tree, 0, n - 1, 0);
    cin >> m;
    while (m--) {
        string action;
        cin >> action;
        if (action == "get-max") {
            int i, j;
            cin >> i >> j;
            cout << query(tree, 0, n - 1, 0, i - 1, j - 1) << endl;
        } else if (action == "update") {
            int i, v;
            cin >> i >> v;
            a[i - 1] = v;
            update(tree, 0, n - 1, 0, i - 1, v);
        }
    }
    return 0;
}