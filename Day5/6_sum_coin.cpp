#include<bits/stdc++.h>
using namespace std;

int n, a[1000001], s, f[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for(int i=0; i<=s; i++) {
        f[i] = INT_MAX;
    }
    f[0] = 0;
    for(int i = 1; i <= s; i++) {
        for(int j = 0; j < n; j++) {
            if (a[j] <= i && f[i-a[j]] + 1 < f[i]){
                f[i] = f[i-a[j]] + 1;
                // cout << f[i] << endl;
            }
        }
        // cout << f[i] << endl;
    }
    cout << f[s];
}
