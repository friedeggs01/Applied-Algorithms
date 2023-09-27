#include<bits/stdc++.h>
using namespace std;
int M[1000][1000];
int P = 1e9 + 7;
int C(int k, int n){
    if(k==0||k==n) {
        M[k][n] = 1;
    } else {
        if (M[k][n] == 0) {
            M[k][n] = (C(k-1, n-1)%P + C(k, n-1)%P)%P;
        }
    }
    return M[k][n];
}
int main() {
    int k, n;
    cin >> k >> n;
    for (int i = 0; i<1000; i++) {
        for(int j = 0; j<1000; j++) {
            M[i][j] = 0;
        }
    }
    long int res = C(k, n);
    cout << res;

    
}