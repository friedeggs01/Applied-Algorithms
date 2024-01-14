#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("6.txt", "r", stdin);
    int n, a[1001];
    cin >> n;
    int longest = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int L[n][n];
    for(int i = 0; i<n; i++) {
        L[i][i] = 1;
        for(int j = i+1; j < n; j++){
            L[j][i] = 1;
        }
    }
    for(int i = 0; i<n; i++) {
        for(int j = 0; j < n; j++){
            cout << L[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i<n; i++) {
        for(int j = i+1; j<n; j++) {
            if (a[i] == a[j]) {
                L[i][j] = 2 + L[i+1][j-1];
                longest = max(longest, L[i][j]);
            } else {
                L[i][j] = L[i+1][j-1];
            }
            cout << i << " " << j << " " << L[i][j] << endl;
        }
    }
    cout << longest;
}
