#include<bits/stdc++.h>
using namespace std;

int n, a[1001], f[1001], truyvet[1001];

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        f[i] = 1;
        for(int j=1; j<i; j++) {
            if (a[j] < a[i]){
                if(f[j] + 1 > f[i]) {
                    f[i] = f[j] + 1;
                    truyvet[i] = j;
                }
            }
        }
        ans = max(ans, f[i]);
    }
    cout << ans;
}
