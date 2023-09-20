// how to manipulate string and set of string
#include<bits/stdc++.h>
using namespace std;
int main() {
    // freopen("3.txt","r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<string> s;
    while(true){
        string temp;
        cin >> temp;
        if(temp == "*") {
            break;
        } else {
            s.insert(temp);
        }
    }
    // for(set<string>::iterator k = s.begin(); k != s.end(); k++) {
    //     cout << *k << endl;
    while(true){
        string query;
        cin >> query;
        if(query == "***") {
            break;
        } else if(query == "find"){
            string k; cin >> k;
            int res = 0; 
            if (s.find(k) != s.end()) res = 1;
            cout << res << endl;
        } else {
            string k; cin >> k;
            int res = 0;
            if (s.find(k) == s.end()) {
                res = 1;
                s.insert(k);
            } 
            cout << res << endl;
        }
    }
    return 0;
}