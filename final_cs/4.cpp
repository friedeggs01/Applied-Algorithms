// Cho n công việc với m người, tìm năng suất nhỏ nhất
#include<bits/stdc++.h>
using namespace std;

int n, m, c[20][20], min_load = INT_MAX, load=0;
int sol[20];
bool check(int v, int k){
    if (k==0) return true;
    if (v > sol[k-1]) return true;
    return false;

}
void TRY(int k){
    // cout << "k: "<< k << endl;
    for(int v=0; v<m; v++){
        // cout << "v: " << v << endl;
        if(check(v, k)) {
            sol[k] = v;
            load += c[k][v];
            if (k == (n-1)) {
                if(load < min_load) {
                    min_load = load;
                    cout << min_load << endl;
                }
            } else {
                TRY(k+1);
            }
            load -= c[k][sol[k]];
        }
    }
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("4.txt", "r", stdin);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> c[i][j];
        }
    }
    TRY(0);
    cout << min_load;
    return 0;
}