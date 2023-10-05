#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("14.txt", "r", stdin);
    string p1, p2, t;
    getline(cin, p1);
    getline(cin, p2);
    getline(cin, t);
    while(true) {
        if(t.find(p1) == std::string::npos) break;
        t.replace(t.find(p1), p1.length(), p2);
    }
    // cout << t.find(p1) << endl;
    cout << t;
}