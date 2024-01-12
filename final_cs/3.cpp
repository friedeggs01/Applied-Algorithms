#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("3.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if(a[i] > a[j] && b[i] > b[j]){
                swap(b[i], b[j]);
            }
        }
    }
    for (auto &i : b) cout << i;
}