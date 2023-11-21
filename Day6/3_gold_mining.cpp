// Bài toán con S(i) = tổng cực đại của dãy con thỏa mãn phần tử cuối cùng là ai
// S(i) = max(ai + S(j) | L1 <= i-j <= L2)
// Khởi tạo deque, lưu trữ các chỉ số j sao cho S(j) không tăng và là ứng viên để tính toán cho bài toán con S(i)
// Mỗi khi xét đến chỉ số i:
//     Đưa hết các chỉ số j ở đầu deque tại đó j<i-l2 ra ngoài(vì nó không là ứng viên để xác định S(i))
//     Đưa hết các chỉ số j ở cuối deque tại đó S(j) < S(i-L1) 



#include<bits/stdc++.h>
using namespace std;

int n, l1, l2, ans=0;
int a[1000001], s[1000001];
deque<int> d; // lưu chỉ số các ứng viên j tham gia vào việc xác định các bài toán con S(i)

int main(){
    freopen("3.txt", "r", stdin);
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cin >> n >> l1 >> l2;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        while(!d.empty() && d.front() < i-l2) {
            d.pop_front();
        }
        int j=i-l1;
        if (j >= 1){
            while(!d.empty() && s[d.back()] < s[j]) {
                d.pop_back();
            }
            d.push_back(j);
        }
        s[i] = a[i] + (d.empty() ? 0 : s[d.front()]);
        ans = max(ans, s[i]);
    }
    cout << ans;
    return 0;
}