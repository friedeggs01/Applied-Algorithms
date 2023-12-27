#include<bits/stdc++.h>
using namespace std;

int n, l1, l2;
int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cin >> n >> l1 >> l2;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n+1, 0);
    for(int i=1; i<=n; i++){
        dp[i]
    }
    int max_gold = 0;
    for (int i = l1; i <= n; i++) {
        max_gold = max(max_gold, dp[i]);
    }

}