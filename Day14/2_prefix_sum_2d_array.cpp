#include<bits/stdc++.h>
using namespace std;

int n, m, a[1001][1001], q, s[1001][1001];

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("2.txt", "r", stdin);
    cin >> n >> m;
    for(int i=0; i<=n; i++){
        s[i][0] = 0;
    }
    for(int j=0; j<=m; j++){
        s[0][j] = 0;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> a[i][j];
            s[i][j] = a[i][j];
            if(i==1 && j==1){
                s[i][j] += 0;
            } else if (i==1 && j>1) {
                s[i][j] += s[i][j-1];
            } else if (i>1 && j==1) {
                s[i][j] += s[i-1][j];
            } else {
                s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
            }

        }
    }
    // for(int i=0; i<=n; i++) {
    //     for(int j=0; j<=m; j++) {
    //         cout << s[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    cin >> q;
    while(q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << s[r2][c2] - s[r1-1][c2] - s[r2][c1-1] + s[r1-1][c1-1] << endl;
    }
}