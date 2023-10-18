#include<bits/stdc++.h>
using namespace std;

int n, a[1000001];
// Dynamic programming
int max_seq() {
    int sum = a[0];
    int ei = a[0];
    int imax = 0;
    int u, v;
    for(int i=1; i<n; i++) {
        u = ei + a[i];
        v = a[i];
        if(u>v) {
            ei = u;
        } else {
            ei = v;
        }
        if(ei>sum) {
            sum = ei;
            imax = i;
        }
    }
    return sum;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    // freopen("2.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << max_seq();
}