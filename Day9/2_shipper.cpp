#include<bits/stdc++.h>
using namespace std;

int n, x[1001], d[1001][1001], m;
vector<int> constraint[10001];

int main() {
    // freopen("2.txt", "r", stdin);
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x[i];
    }
    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++) {
            cin >> d[i][j];
        }
    }
    cin >> m;
    int a, b;
    for(int i=0; i<m ;i++){
        cin >> a >> b;
        constraint[b].push_back(a);
    }
    for(int i = 0; i<n; i++) {
        for(int j=i+1; j<n; j++){
            auto it = find(constraint[x[i]].begin(), constraint[x[i]].end(), x[j]);
            if(it != constraint[x[i]].end()){
            cout << -1;
            return 0;
            }
        }
    }
    int sum = 0;
    for(int i=0; i<n; i++) {
    }
    for(int i=0; i<n-1; i++) {
        sum += d[x[i]-1][x[i+1]-1];
        // cout << d[x[i]-1][x[i+1]-1] << endl;
    }
    sum += d[x[n-1]-1][x[0]-1];
    cout << sum;
}

