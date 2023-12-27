#include<bits/stdc++.h>
using namespace std;

int n, Q, a[1000001];

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("4.txt", "r", stdin);
    cin >> n >> Q;
    cin >> a[0];
    for(int i=1; i<n; i++){
        cin >> a[i];
    }
    int res = 0, s = 0;
    int i=0;
    for(int j=0; j<n; j++) {
        s += a[j];
        while(s>Q) {
            s -= a[i];
            i++;
        }
        res = max(res, j-i+1);
    }
    cout << res;
}