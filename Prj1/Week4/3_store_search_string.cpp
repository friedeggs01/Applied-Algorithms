#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    // freopen("3.txt", "r", stdin);
    set<string> str;
    string word;
    while(true) {
        cin >> word;
        if(word == "*") {
            break;
        } else {
            str.insert(word);
        }
    }
    string query;
    while(true) {
        cin >> query;
        if(query == "***") {
            break;
        } else if (query == "find") {
            cin >> word;
            auto it = str.find(word);
            if(it != str.end()) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }

        } else{
            cin >> word;
            auto result = str.insert(word);
            if(result.second) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
}