#include<bits/stdc++.h>
using namespace std;
int main() {
    // freopen("5.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    queue<int> Q;
    while(true){
        string temp;
        cin >> temp;
        if(temp == "#"){
            break;
        } else if (temp == "PUSH") {
            int k; cin >> k;
            Q.push(k);
        } else {
            if (Q.empty()) {
                cout << "NULL" << endl;
            } else {
                cout << Q.front() << endl;
                Q.pop();
            }
        }
    }
}