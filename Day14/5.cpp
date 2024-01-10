// idea: segment tree
// cây nhị phân đầy đủ, mỗi nút quản lý 1 đoạn con trên cây, nút gốc có id = 1 quản lí đoạn chỉ số 1,n
// nút có id = v, quản lý đoạn con với chỉ số [i, j]
// con trái quản lý i, (i+j)/2 --- con phải quản lý (i+j)/2+1, j
// bản chất vẫn thao tác trên mảng, cha là i, con trái là 2i, con phải là 2i+1

#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> arr;
vector<int> maxVal;

void build(int id, int left, int right) {
    if (left == right) {
        maxVal[id] = arr[left];
        return;
    }
    
    int mid = (left + right) / 2;
    int LC = 2 * id; // left child
    int RC = 2 * id + 1; // right child
    
    build(LC, left, mid); // build left subtree
    build(RC, mid + 1, right); // build right subtree
    
    maxVal[id] = max(maxVal[LC], maxVal[RC]); // update the maximum value of the current node
}

int getMaxFromNode(int id, int L, int R, int i, int j) {
    // return the max value of ai, ..., aj from the node (id, L, R)
    if (i>R || j<L) { // [L, R] not join [i,j]
        return 0;
    } 
    if (i <= L && j >= R) {  // [L, R] is within [i, j]
        return maxVal[id];
    }
    int mid = (L+R)/2;
    int LC = 2*id; // left-child and right-child
    int RC = 2*id + 1;
    int maxLeft = getMaxFromNode(LC, L, m, i, j);
    int maxRight = getMaxFromNode(RC, m+1, R, i, j);
    return max(maxLeft, maxRight);
    }

void updateFromNode(int id, int L, int R, int index, int value) {
    // propagate from the node (id, L, R) by the update: a[index] = value
    if(L>R) return;
    if(index<L || index>R) return;
    if (L==R){
        maxVal[id] = value;
        return;
    }
    int mid = (L+R)/2;
    int LC = 2*id; // left-child and right-child
    int RC = 2*id+1;
    updateFromNode(LC, L, m, index, value);
    updateFromNode(RC, m+1, R, index, value);
    maxVal[id] = max(maxVal[LC], maxVal[RC]);
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    freopen("5.txt", "r", stdin);
    
    cin >> n;
    arr.resize(n);
    maxVal.resize(4 * n);
    maxVal.assign(maxVal.size(), 0); // Allocate space for the segment tree
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Build the initial segment tree
    build(1, 0, n - 1);
    
    cin >> m;
    
    while (m--) {
        string t;
        int a, b;
        cin >> t;
        
        if (t == "get-max") {
            cin >> a >> b;
            int ans = getMaxFromNode(1, 1, n, a, b);
            cout << ans << "\n";
        } else {
            cin >> a >> b;
            updateFromNode(1, 1, n, a, b);
        }
    }
    
    return 0;
}