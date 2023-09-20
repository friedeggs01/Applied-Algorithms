#include<bits/stdc++.h>
using namespace std;
int main() {
    // freopen("6.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string, int> M;
    string str;
    while(cin >> str) {
        M[str]++;
    }
    for(map<string, int>::iterator p = M.begin(); p != M.end(); p++) {
        cout << p->first << " " << p->second << endl;
    }
}