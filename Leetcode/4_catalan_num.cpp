#include<bits/stdc++.h>
using namespace std;

vector<int> cal(10001, 0);
int n;
int solve() {
    if(n==0 || n==1) {
        return 1;
    }
    cal[0] = cal[1] = 1;
    for(int i=2; i<n+1; i++){
        for(int j = 0; j < i; j++) {
            cal[i] += cal[j] * cal[i-j-1];
        }
    }
    return cal[n];
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cin >> n;
    cout << solve();
}