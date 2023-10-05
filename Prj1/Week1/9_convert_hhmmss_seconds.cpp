#include<bits/stdc++.h>
using namespace std;

int main() {
    int h, m, s;
    string str;
    cin >> str;
    if (str.length() != 8) {
        cout << "INCORRECT";
    } else {
        for(int i = 0; i < 8; i++) {
            if(i == 2 || i == 5) {
                if(str[i] != ':') {
                    cout << "INCORRECT";
                    return 0;
                }
            } else {
                if(str[i] <= '0' && str[i] >= '9'){
                    cout << "INCORRECT";
                    return 0;
                }
            }  
        }
        h = ((int)str[0] - 48)*10 + (int)str[1] - 48;
        if(h>23) {
            cout << "INCORRECT";
            return 0;
        }
        m = ((int)str[3] - 48)*10 + (int)str[4] - 48;
        if(m>59) {
            cout << "INCORRECT";
            return 0;
        }
        s = ((int)str[6] - 48)*10 + (int)str[7] - 48;
        if(s>59) {
            cout << "INCORRECT";
            return 0;
        }
        cout << (h*3600 + m*60 + s);
    }
}