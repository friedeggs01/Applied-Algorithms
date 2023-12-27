#include<bits/stdc++.h>
using namespace std;

int n, a[100001], k, s[100001];

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("1.txt", "r", stdin);
    cin >> n;
    cin >> a[1];
    s[0] = 0;
    s[1] = a[1];
    for(int i=2; i<=n; i++) {
        cin >> a[i];
        s[i] = a[i] + s[i-1];
    }
    cin >> k;
    while(k--){
        int x, y;
        int sum = 0;
        cin >> x >> y;
        cout << (s[y] - s[x-1]) << endl;
    }
}