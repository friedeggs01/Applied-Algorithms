#include<bits/stdc++.h>
using namespace std;

long long n, a[10000001], ans = -1;
long long mo, me;

// a[i] is sum from a[1] +...+ a[i]
long long max_even_seq() {
    for(int i=1; i<=n; i++){
        // cout << ans << endl;
        if(a[i]%2 == 0){
            ans = max(ans, a[i] - mo);
            mo = min(mo, a[i]);
        } else {
            ans = max(ans, a[i] - me);
            me = min(me, a[i]);
        }
        // cout << ans << endl;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    freopen("3.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    // cout << "eeeeeeeeeee" << endl;
    cout << max_even_seq();
}