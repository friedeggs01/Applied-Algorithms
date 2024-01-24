#include<bits/stdc++.h>
using namespace std;

int f[1001][1001];

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    string s, t;
    cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    f[0][0] = 0;
    
    for (int i=0;i<=n;i++){
        for(int j=1; j<=m; j++){
            if (s[i] == t[j]){
                f[i][j] = f[i-1][j-1] + 1;
            } else {
                f[i][j] = max(f[i-1][j], f[i][j-1]);
            }
        }
    }
    cout << f[n][m];
}