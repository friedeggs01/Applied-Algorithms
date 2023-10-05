#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, count=0;
    cin >> n >> k;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    for(int i=0; i<k; i++) {
        sum += a[i];
    }
    if(sum % 2 == 0) {
        count++;
    }
    for(int i=0; i<n-k+1; i++) {
        sum -= a[i];
        sum += a[i+k];
        if(sum % 2 == 0) {
            count++;
        }
    }
    if (count == 3) {
        count = 2;
    }
    cout << count;
}