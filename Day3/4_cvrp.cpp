#include<bits/stdc++.h>
using namespace std;

int n, K, Q;
int d[15], visited[15], c[15][15];
int x[15], y[8], load[8];
int f=0, ans=INT_MAX;
void TRY_X(int i, int k);
// số chặng đã đi qua nb segment
bool checkY(int k) {
    return !visited[y[k]];
}
void TRY_Y(int k) {
    for(int v = y[k-1]; v<n; v++) {
        if(checkY(k)) {
            y[k] = v;
            load[k] += d[v];
            f += c[0][y[k]];
            visited[v] = true;
            nbsegment += 1;
        }
        if (k==K){
            TRY_X(y[1], k);
            TRY_Y(k+1);
        }
    }
}
bool checkX(int v, int i, int k){
    return !visited[v] && (load[k] + d[v] <= Q);
}
void TRY_X(int i, int k) { // thử lộ trình xi trên route k
    for(int v = 0; v < n; v++) {
        if(checkX(v,i, k)){
            x[i] = v;
            load[k] += d[v];
            f += c[i][x[i]];
            visited[v] = true;
            // if v là 0 thì là kho, còn v khác không thì

            if(v==0) {
                if(k==K) {
                    solution(nb segment = N+K);
                } else {
                    TRY_X(y[k+1], k+1);
                }
            } else {
                TRY_X(v, k);
            }
            load[k] -= d[v];
            f -= c[i][x[i]];
            visited[v] = false;
        }
    }
}

int main() {
    freopen("4.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> K >> Q;
    for(int i=0; i<=n; i++) {
        if(!(i==0)) {
            cin >> d[i];
        }
        for(int j=0; j<=n; j++) {
            cin >> c[i][j];
        }
    }
    TRY_Y(1);
    cout << ans;
}