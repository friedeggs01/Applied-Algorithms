#include<bits/stdc++.h>
using namespace std;

int n;

struct Point{
    double x, y;
};
struct Line{
    int a, b, c;
};

void makeLine(Point& A, Point& B, Line& L){
    L.a = A.y - B.y;
    L.b = B.x - A.x;
    L.c = A.x * B.y - A.y*B.x;
}
int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("2.txt", "r", stdin);
    cin >> n;
    for(int i=0; i<n; i++) {
        Point A, B, C;
        Line L;
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
        makeLine(B, C, L);
        if(L.a*A.x + L.b*A.y + L.c == 0 && A.x<= max(B.x, C.x) && A.x >= min(B.x, C.x) && A.y <= max(B.y, C.y) && A.y >= min(B.y, C.y)) {
            cout << 1 << endl;
            continue;
        }
        cout << 0 << endl;
    }
}