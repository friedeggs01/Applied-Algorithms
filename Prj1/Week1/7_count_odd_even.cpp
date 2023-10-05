#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, odd=0, even=0;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    cout << odd << " " << even;
}