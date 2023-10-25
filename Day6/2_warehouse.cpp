
// Đặt bài toán con ứng với chỉ số i -> xây dựng công thức truy hồi

// s[i] tổng lượng hàng max cho đến trạm i -> thiếu thông tin vì còn ràng buộc về thời gian
// s[i][k] tổng lượng hàng max cho đến trạm i (có lấy hàng ở i và tổng thời gian lấy hàng là k)
// s[i][k] = max(s[j][k-ti] + ai| i-j <= D)

#include<bits/stdc++.h>
using namespace std;

int n, t, d, res=0;
vector<int> a(1001);
vector<int> ti(1001);
int s[1001][101];

int compute(int i, int k) {
    if(i==1){    // base case
        if(k == ti[1]) s[i][k] = a[i];
        else s[i][k] = 0;
    } else {
        if(s[i][k] == -1) {
            for(int j = max(i - d, 1); j < i; j++){
                int tmp = 0;
                if(k >= ti[i])
                    tmp = compute(j, k-ti[i]) + a[i];
                s[i][k] = max(s[i][k], tmp);
            }
        }
    }
    return s[i][k];
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
    freopen("2.txt", "r", stdin);
    cin >> n >> t >> d;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> ti[i];
    }
    for(int i=1; i <= n; i++) {
        for(int j=0; j<= t;j++) {
            s[i][j] = -1;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<= t; j++){
            // use max because you dont have to reach location n
            res = max(compute(i, j), res);
        }
    }
    cout << res;
    return 0;
}