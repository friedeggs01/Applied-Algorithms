#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("3.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie();
    stack<char> s;
    bool check = false;
    char temp;
    while(cin >> temp){
        if (s.empty()) {
            s.push(temp);
            check = false;
        } else if(s.top() == '(' && temp == ')' || s.top() == '{' && temp == '}' || s.top() == '[' && temp == ']') {
                s.pop();
                check = true;
        } else {
            s.push(temp);
        }
    }
    if(check == true) {
        cout << 1;
    } else {
        cout << 0;
    }
    
}