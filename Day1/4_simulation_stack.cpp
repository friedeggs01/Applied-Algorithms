#include<bits/stdc++.h>
using namespace std;
int main() {
    // freopen("4.txt","r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> S;
    while(true){
        string temp;
        cin >> temp;
        if(temp == "#"){
            break;
        } else if (temp == "PUSH") {
            int k; cin >> k;
            S.push(k);
        } else {
            if (S.empty()) {
                cout << "NULL" << endl;
            } else {
                cout << S.top() << endl;
                S.pop();
            }
        }
    }

}