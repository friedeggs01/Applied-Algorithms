#include<bits/stdc++.h>
using namespace std;
// chiều cao các đỉnh trong stack giảm dần từ đỉnh xuống đáy
// chừng nào còn tồn tại các cột lớn hơn chiều cao tại cột i -> lấy ra tiếp
// Complexity time: O(m) vì mỗi cột i được đưa vào stack và lấy ra đúng 1 lần
int n, m;
int matrix[1001][1001];

int largest_rectangle(int high[]){
    stack<pair<int, int>> s;
    int max_area = 0;

    for(int i=0; i<m; i++) {
        int start = i;
        int height = high[i];
        while(!s.empty() && (height < s.top().second)) {
            int end_id = s.top().first;
            int end_height = s.top().second;
            s.pop();
            start = end_id;
            max_area = max(max_area, (i - end_id) * end_height);
        }
        s.push({start, height});
    }
    // bởi vì max_area được update khi tìm thấy high < high trong stack -> còn dư những cột cuối mà high không giảm
    while(!s.empty()){
        int end_id = s.top().first;
        int end_height = s.top().second;
        s.pop();
        max_area = max(max_area, (m - end_id) * end_height);
    }
    
    return max_area;
}

int largest_black_subrectangle(){
    int high[m] = {};
    int max_area = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m ; j++) {
            if(matrix[i][j] == 1) high[j]++;
            else high[j] = 0;
        }
        max_area = max(max_area, largest_rectangle(high));
    }
    return max_area;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("4.txt", "r", stdin);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << largest_black_subrectangle();
    return 0;
}