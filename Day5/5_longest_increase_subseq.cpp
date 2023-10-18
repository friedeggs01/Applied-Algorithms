#include <bits/stdc++.h>
#pragma GCC optimize("03")
#pragma GCC target ("sse4")
using namespace std;

int n, a[1000000];

int increase_seq() {
    int ans = 1;
    vector<int> s(n);
    for (int i = 1; i < n; i++) {
        s[i] = 1;
        for(int j=0; j<i; j++) {
            if (a[j] < a[i]) {
                if (s[i] < s[j]+1) {
                    s[i] = s[j]+1;
                }
            }
        }
    }
    return *max_element(s.begin(), s.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    // freopen("5.txt", "r", stdin);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << increase_seq();
}