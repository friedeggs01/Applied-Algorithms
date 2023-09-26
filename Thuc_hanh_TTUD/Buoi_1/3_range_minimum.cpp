#include<bits/stdc++.h>
using namespace std;

int find_min_of_range(int a[], int x, int y) {
    int min = a[x];
    for (int i = x+1; i <= y; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int main() {
    freopen("3.txt","r", stdin);
    // ios_base::sync_with_stdio(false); // cannot use those statements when used scanf
    // cin.tie(NULL);
    int n, m, q = 0;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        q += find_min_of_range(a, x , y);
    }
    cout << q << endl;
}