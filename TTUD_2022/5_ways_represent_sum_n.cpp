#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    int n;
    cin >> n;
    int m = 1000000007;
    vector<int> dp(51);
    dp[0] = 1;
    for(int i=1; i<=n+1; i++){
        for(int j=i; j<=n+1; j++){
            dp[j] += dp[j-i];
            dp[j] %= m;
        }
    }
    cout << dp[n] % m;
}
// i - đồng xu mệnh giá i
// khi sử dụng đồng xu mệnh giá i rồi, vậy chỉ còn lại j-i tiền