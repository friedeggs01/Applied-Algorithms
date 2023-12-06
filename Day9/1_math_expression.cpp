#include<bits/stdc++.h>
using namespace std;

string t;
stack<unsigned long long int> s;
int q = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("1.txt", "r", stdin);
    getline(cin, t);
    // cout << t;
    unsigned long long int ans=0;
    for(int i=0; i<t.size(); i++) {
        if(t[i] >= '0' && t[i] <= '9') {
            if(t[i+1] >= '0' && t[i+1] <= '9') {
                if(t[i+2] >= '0' && t[i+2] <= '9') {
                    int temp = (t[i] - '0')*100 + ((t[i+1] - '0')*10) + (t[i+2] - '0');
                    i += 2;
                    // cout << temp << endl;
                    s.push(temp);
                } else {
                    int temp = (t[i] - '0')*10 + ((t[i+1] - '0'));
                    i++;
                    // cout << temp << endl;
                    s.push(temp);
                }
            } else {
                int temp = (t[i] - '0');
                // cout << temp << endl;
                s.push(temp);
            } 
        } 

        if(t[i] == '*'){
            int temp;
            if(t[i+1] >= '0' && t[i+1] <= '9') {
                if(t[i+2] >= '0' && t[i+2] <= '9') {
                    if(t[i+3] >= '0' && t[i+3] <= '9') {
                        temp = (t[i+1] - '0')*100 + ((t[i+2] - '0')*10) + (t[i+3] - '0');
                        i += 3;
                        // cout << s.top() << " " << temp << endl;
                        int mul = (s.top() %q * temp) % q;
                        s.pop();
                        s.push(mul);
                    } else {
                        temp = (t[i+1] - '0')*10 + ((t[i+2] - '0'));
                        i+= 2;
                        // cout << s.top() << " " << temp << endl;
                        int mul = (s.top() % q * temp) % q;
                        s.pop();
                        s.push(mul);
                    }
                } else {
                temp = (t[i+1] - '0');
                i+= 1;
                // cout << s.top() << " " << temp << endl;
                int mul = (s.top() * temp) % q;
                s.pop();
                s.push(mul);
                }
            } 
        } 

    }
    while(!s.empty()) {
        // cout << s.top() << endl;
        ans += s.top();
        s.pop();
        ans %= q;

    }
    cout << ans;
}
