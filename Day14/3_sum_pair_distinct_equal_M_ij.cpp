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
    int cnt = 0;
    int i=0, j=n-1; // Kỹ thuật 2 con trỏ
    while(i<j) {
        if (a[i]+a[j] == M) {
            cnt++;
            i++;
            j--;
        } else if (a[i] + a[j] < M) {
            i++;
        } else {
            j--;
        }
    }
    cout << cnt;
    return 0;
}