#include <iostream>
#include <map>
#pragma GCC optimize("03")
#pragma GCC target ("sse4")
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    freopen("2.txt", "r", stdin);
    int n, num;
    cin >> n;
    map<int, int> m;
    for (int i=0; i<n; i++) {
        cin >> num;
        if(m[num] == 1) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
            m[num] = 1;
        }
    }
    return 0;
}