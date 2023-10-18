#include<bits/stdc++.h>
using namespace std;

int n, m, x[10001], y[10001], d[10001][10001];

int lcm() {
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(x[i] == y[j]){
                d[i][j] = d[i-1][j-1] + 1;
            } else if (d[i-1][j] >= d[i][j-1]) {
                d[i][j] = d[i-1][j];
            } else {
                d[i][j] = d[i][j-1];
            }
        }
    }
    return d[m][n];
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    // freopen("4.txt", "r", stdin);
    cin >> m >> n;
    d[0][0]=0;
    for(int i = 1; i <= m; i++) {
        cin >> x[i];
        d[i][0] = 0;
    }
    for(int i=1; i <= n; i++) {
        cin >> y[i];
        d[0][i] = 0;
    }
    cout << lcm();
}