#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("2.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie();
    queue<int> q;
    while(true){
        string temp;
        cin >> temp;
        if (temp == "#") break;
        else if (temp == "PUSH") {
            int k; cin >> k;
            q.push(k);
        } else {
            if(q.empty()) {
                cout << "NULL" << endl;
            } else {
                cout << q.front() << endl;
                q.pop();
            }
        }
    }
}