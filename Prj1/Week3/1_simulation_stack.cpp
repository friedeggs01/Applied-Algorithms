#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("1.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie();
    stack<int> s;
    while(true){
        string temp;
        cin >> temp;
        if(temp == "#"){
            break;
        } else if(temp == "PUSH") {
            int k; cin >> k;
            s.push(k);
        } else {
            if(s.empty()) {
                cout << "NULL" << endl;
            } else {
                cout << s.top() << endl;
                s.pop();
            }
        }
    }
}