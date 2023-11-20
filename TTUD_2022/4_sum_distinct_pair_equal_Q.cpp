#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    int n, q;
    cin >> n >> q;
    int cnt=0;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i=0; i<n; i++){
        int x = q-a[i];
        int y = lower_bound(a+i+1, a+n, x) - a;
        int z = upper_bound(a+i+1, a+n, x) - a;
        cnt = cnt + z - y;
    }
    cout << cnt;
    return 0;
}