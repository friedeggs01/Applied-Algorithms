#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    bool check = true;
    int sum=0;
    getline(cin, str);
    for(int i=0; i<str.size(); i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            if(str[i+1] >= '0' && str[i+1] <= '9') {
                if(str[i+2] >= '0' && str[i+2] <= '9') {
                    sum += (str[i] - '0')*100 + ((str[i+1] - '0')*10) + (str[i+2] - '0');
                    i += 2; 
                } else {
                    sum += (str[i] - '0')*10 + ((str[i+1] - '0'));
                    i++;
                }
            } else {
                sum += (str[i] - '0');
            } 
        } 
        if(str[0] < '0' || str[0] > '9' || str[str.size() - 1] <'0' || str[str.size() - 1] > '9' ) {
            cout << "INCORRECT";
            return 0;
        }
    }
    if (check == true) {
        cout << sum;
    }

}