#include<bits/stdc++.h>
using namespace std;

int n, m, a[100], b[100], cnt=0;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("5.txt", "r", stdin);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        if(a[i] == 0){
            cnt++;
        }
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> b[i];
        if(b[i] == 0){
            cnt++;
        }
    }
    cout << cnt;
}