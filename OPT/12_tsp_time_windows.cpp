#include<bits/stdc++.h>
using namespace std;

int n, e[1001], l[1001], t[1001], d[1001][1001];
vector<int> r;

int main () {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("12.txt", "r", stdin);
    cin >> n;
    bool visited[n];
    memset(visited, false, sizeof(visited));
    visited[n] = false;
    visited[0] = true;
    for(int i=1; i<=n; i++) {
        cin >> e[i] >> l[i] >> t[i];
    }

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++){
            cin >> d[i][j];
        }
        d[i][i] = INT_MAX;
    }
    visited[0] = true;
    int Prev = 0;
    // for(int i=0; i<=n; i++) {
    //     cout << visited[i] << " ";
    // }
    // while(count(visited, visited + n+1, false) > 0){
    //     int* minElement = min_element(d[Prev], d[Prev] + n+1);
    //     int j = minElement - d[Prev];
    //     if (!visited[j]) {
    //         r.push_back(j);
    //         visited[j] = true;
    //         Prev = j;
    //     } else {
    //         d[Prev][j] = INT_MAX;
    //     }
    // }
    while(count(visited, visited + n+1, false) > 0){
        int* minElement = min_element(e, e + n+1);
        int j = minElement - e;
        if (!visited[j]) {
            r.push_back(j);
            visited[j] = true;
            Prev = j;
        } else {
            e[Prev] = INT_MAX;
        }
    }
    cout << n << endl;
    for (auto i : r) {
        cout << i << " ";
    }
    cout << endl;
}