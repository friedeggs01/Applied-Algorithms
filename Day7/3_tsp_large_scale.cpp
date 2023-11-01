#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("3.txt", "r", stdin);
    cin >> n;
    cout << n << endl;
    int c[n][n];
    bool visited[n];
    for(int i=0; i<n; i++) {
        visited[i] = false;
        for(int j=0; j<n; j++) {
            cin >> c[i][j];
            if(i == j) {
                c[i][j] = INT_MAX;
            }
        }
    }

    cout << 1 << " ";
    visited[0] = true;
    int Prev = 0;

    while(count(visited, visited + n, false) > 0){
        int* minElement = min_element(c[Prev], c[Prev] + n);
        int j = minElement - c[Prev];
        if (visited[j] == false) {
            cout << (j+1) << " ";
            visited[j] = true;
            Prev = j;
        } else {
            c[Prev][j] = INT_MAX;
        }
    }
}