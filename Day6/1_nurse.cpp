//a[n] chuỗi 1 (ngày đi làm) tiên tiếp >= k1 và <= k2 giữa các chuỗi 1 liên tiếp có đúng 1 bit 0
// *Bài toán con: s1[i] là số lượng xâu thỏa mãn đề bài, độ dài i, bit i bằng 1
                // s0[i] là số lượng xâu thỏa mãn đề bài, độ dài i, bit i bằng 0
                // s0[i] = s1[i-1] 
                // s1[i] = sum_j(s0[j]) (i-j chạy trong khoảng k1, k2)

#include<bits/stdc++.h>
using namespace std;
vector<int> s1(1001);
vector<int> s0(1001);
int n, k1, k2;
int solve(){
    for(int i=2; i<=n; i++){
        s0[i] = s1[i-1];
        s1[i] = 0;
        for(int j = max(i-k2, 0); j<= i-k1; j++) {
            // cout << j << " " << endl;
            s1[i] += s0[j];
        }
        // cout << s0[i] << " " << s1[i] << endl;
    }
    return s1[n] + s0[n];
}

int main() {
    freopen("1.txt", "r", stdin);
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cin >> n >> k1 >> k2;
    s1[0] = 0;
    s0[0] = 1;
    s1[1] = 0;
    s0[1] = 1;
    cout << solve();
    return 0;
}