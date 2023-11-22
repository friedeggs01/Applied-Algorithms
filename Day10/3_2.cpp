#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> c(101);
vector<vector<int>> dp(10001, vector<int>(101, -1));

int compute(int amount, int index) {
    if (amount == 0)
        return 1;

    if (amount < 0 || index >= K)
        return 0;

    if (dp[amount][index] != -1)
        return dp[amount][index];

    int count = 0;
    for (int v = 0; v <= N / c[index]; v++) {
        count += compute(amount - v * c[index], index + 1);
    }

    dp[amount][index] = count;
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("3.txt", "r", stdin);

    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> c[i];
    }
    cout << compute(N, 0);
    return 0;
}