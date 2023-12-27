#include<bits/stdc++.h>
using namespace std;
#define N 100001

struct Point {
    int x, y;
};
int n;
Point p[N];
vector<Point> C;

int distance(Point a, Point b) {
    int x = a.x - b.x;
    int y = a.y - b.y;
    return x*x + y*y;
}

int crossProduct(Point o, Point a, Point b){
    // return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
    int xa = a.x - o.x; int ya = a.y - o.y;
    int xb = b.x - o.x; int yb = b.y - o.y;
    return xa * yb - ya * xb;
}

bool cmp(Point a, Point b){ // hàm so sánh sử dụng trong sort
    int cp = crossProduct(p[0], a, b);
    return cp == 0 ? distance(p[0], a) < distance(p[0], b):cp > 0;
}

int counterclockwise(Point a, Point b, Point c){ // xác định chiều quay tia ab đến ac
    int res = crossProduct(a, b, c);
    if(res==0) return 0;
    else if (res<0) return -1;
    else return 1;
}

void solve() { // thuật toán graham scan
    int k=0;
    for(int i=1; i<n; i++) { // tìm điểm bên trái dưới nhất (x min và y min) - là điểm chắc chắn thuộc bao lồi. Cho điểm này thành p[0]
        if(p[i].y < p[k].y || (p[i].y == p[k].y && p[i].x < p[k].x)) k=i;
    }
    swap(p[0], p[k]);
    sort(p+1, p+n, cmp); // sắp xếp các điểm còn lại theo góc với điểm gốc là p[0]
    C.push_back(p[0]); C.push_back(p[1]);
    for(int i=2; i<n; i++) {
        // xóa điểm ở đỉnh của stack chừng nào ccw của 3 điểm không dương
        while(C.size()>1 && counterclockwise(C[C.size()-2], C[C.size()-1], p[i]) <= 0){ 
            C.pop_back();
        }
        C.push_back(p[i]);
    }
    cout << C.size() << endl;
    for(int i=0; i<C.size(); i++){
        cout << C[i].x << " " << C[i].y << endl;
    }
}

int main() {
    // freopen("4.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
    }
    solve();
    return 0;    
}