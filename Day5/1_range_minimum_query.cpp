#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

int n, m, sum = 0, M[100][1000001], a[1000001];

void preprocessing() {
    for(int j=0; (1<<j)<=n; j++) {
        for(int i = 0; i < n; i++) {
            M[j][i] = -1;
        }
    }
    for(int i = 0; i < n; i++) M[0][i] = i; // if length is zero
    for(int j = 1; (1 << j) <= n; j++) {
        for(int i=0; i + (1<<j) - 1 < n; i++) {
            if(a[M[j-1][i]] < a[M[j-1][i+(1<<(j-1))]]) {
                M[j][i] = M[j-1][i]; 
            } else {
                M[j][i] = M[j-1][i +(1 << (j-1))];
            }
        }
    }
}
int rmp(int i, int j) {
    int k = log2(j-i+1);
    int p2k = (1 << k); //pow(2,k)
    if(a[M[k][i]] <= a[M[k][j-p2k+1]]){
        return M[k][i];
    } else {
        return M[k][j-p2k+1];
    }
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    // freopen("1.txt", "r", stdin);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    preprocessing();
    cin >> m;
    int x, y;
    while(m--){
        cin >> x >> y;
        sum += a[rmp(x, y)];
    }
    cout << sum;
}