#include<bits/stdc++.h>
using namespace std;

int n;
int m = 1000000007;
vector<int> dp(1001, 0);

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cin >> n;
    dp[0] = 1;
    for (int i=1;i<=n;i++) {
        for (int j=i; j <=n; j++){
            dp[j] += dp[j-i];
            dp[j] %= m;
        }
    }
    cout << dp[n] % m;
}

// dp[i] + (j-i) = j
// i kiểu đồng xu mệnh giá 1, 2, ..., n