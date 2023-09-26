#include<bits/stdc++.h>
using namespace std;

int rectangle_largest(int n, int m, int a[][]){
    int heights[m] = {};
    int maxArea = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int bit = matrix[i][j];
            if
        }
    }
} 

int main() {
    freopen("4.txt", "r", stdin);
    ios_base::sync_with_stdio(false); // cannot use those statements when used scanf
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << rectangle_largest(n, m, a) << endl;
    return 0;
}