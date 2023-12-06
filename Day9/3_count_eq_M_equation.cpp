#include <iostream>
using namespace std;

int a[1001], c[1001];
int sum = 0;
int N, K;
int cnt = 0;

bool check(int v, int k) {
    return (sum + c[k] * v <= N);
}

void TRY(int k) {
    for (int v = N; v >= 0; v--) {
        if (check(v, k)) {
            sum += c[k] * v;
            a[k] = v;
            if (k == K - 1 && sum == N) {
                cnt++;
            } else if (k < K - 1) {
                TRY(k + 1);
            }
            sum -= c[k] * v;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("3.txt", "r", stdin);
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> c[i];
    }
    TRY(0);
    cout << cnt;

    return 0;
}