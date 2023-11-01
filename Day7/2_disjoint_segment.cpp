// Idea: Sort các đoạn theo thứ tự không giảm của đầu mút phải: b1 <= b2 <=... 
// Duyệt DS từ trái qua phải, mỗi đoạn (Ai, bi) nếu không giao với đoạn đã chọn thì chọn đoạn này

#include<bits/stdc++.h>
using namespace std;

int n;
pair<int, int> seg[100001];

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("2.txt", "r", stdin);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> seg[i].first >> seg[i].second;
    }
    sort(seg, seg+n, compare);
    int counting = 1;
    int prev_b = seg[0].second;
    for(int i=1; i<n; i++) {
        if(seg[i].first > prev_b) {
            counting++;
            prev_b = seg[i].second;
        }
    }
    cout << counting;
}