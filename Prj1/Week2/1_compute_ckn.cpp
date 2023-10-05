#include<bits/stdc++.h>
using namespace std;
int c[1001][1001];
int p = 1e9 + 7;
int C(int k, int n) {
    if (k==n || k==0) {
        c[k][n] = 1;
    } else {
        if(c[k][n] == 0) {
            c[k][n] = (C(k-1, n-1)%p + C(k, n-1)%p)%p;
        }
    }
    return c[k][n];
}
int main() {
    int k, n;
    cin >> k >> n;
    for(int i=0; i<1000; i++) {
        for(int j=0; j<1000; j++){
            c[i][j] = 0;
        }
    }
    cout << C(k, n);
}