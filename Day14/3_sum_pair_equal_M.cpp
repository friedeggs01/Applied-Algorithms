#include<bits/stdc++.h>
using namespace std;

int n, M, a[1000001];

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("3.txt", "r", stdin);
    cin >> n >> M;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n);
    int x, cnt = 0;
    for(int i=0; i<n-1; i++){
        x = M - a[i];
        int y = lower_bound(a+i+1, a+n, x) - a; // search for index of first in range [a+i+1, a+n) that is not less than x
        int z = upper_bound(a+i+1, a+n, x) - a; // search for index of first in range [a+i+1, a+n) that is greater than x
        cnt = cnt+z-y;
    }
    cout << cnt;
    return 0;
}