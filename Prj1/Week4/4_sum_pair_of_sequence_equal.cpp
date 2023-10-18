#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio();
    cin.tie();
    int countt = 0;
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i=0; i<n ;i++){
        cin >> a[i];
    } 
    sort(a, a+n);
    int x=0, y, z;
    for(int i=0; i<n-1; i++){
        x = m - a[i];
        int y = lower_bound(a+i+1, a+n, x) - a;
        int z = upper_bound(a+i+1, a+n, x) - a;
        countt = countt+z-y;
    }
    cout << countt;
}