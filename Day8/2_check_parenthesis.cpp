#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("2.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie();
    stack<char> s;
    bool check = false;
    char tmp;
    while(cin >> tmp){
        if (s.empty()) {
            s.push(tmp);
            check = false;
        } else if(s.top() == '(' && tmp == ')' || s.top() == '{' && tmp == '}' || s.top() == '[' && tmp == ']') {
                s.pop();
                check = true;
        } else {
            s.push(tmp);
        }
    }
    if(check == true) {
        cout << 1;
    } else {
        cout << 0;
    }
    
}