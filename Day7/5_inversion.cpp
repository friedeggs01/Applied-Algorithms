#include<iostream>
using namespace std;

int n, a[1000005];
int ta[1000005];
int q = 1000000007;

int merge(int s, int m, int e) {
    int i = s, j = m+1;
    unsigned long long int cnt=0;
    for(int k = s; k<=e; k++) {
        if (i > m) {
            ta[k] = a[j++];
        } else if (j > e) {
            ta[k] = a[i++];
        } else {
            if(a[i] <= a[j]) {
                ta[k] = a[i++];
            } else {
                ta[k] = a[j++];
                cnt += (m-i+1);
                cnt %= q;
            }
        }
    }
    for(int k = s; k<=e; k++) {
            a[k] = ta[k];
    }
    return cnt;
}

int solve(int s, int e) {
    if (s >= e) {
        return 0;
    }
    int m = s + (e - s) / 2;
    return ((solve(s, m) + solve(m + 1, e))%q + merge(s, m, e))%q;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("5.txt", "r", stdin);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << solve(0, n-1);
}
