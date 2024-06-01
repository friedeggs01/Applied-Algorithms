#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("1.txt", "r", stdin);
    string a, b;
    int sa=0, sb=0;
    while(cin >> a){
        cin >> b;
        if (a=="A" && b=="X") {
            sa+=4;
            sb+=4;
        } else if (a=="B" && b=="Y") {
            sa+=5;
            sb+=5;
        } else if (a=="C" && b=="Z") {
            sa+=6;
            sb+=6;
        } else if (a=="A" && b=="Y") {
            sa+= 1;
            sb+= 8;
        } else if (a=="A" && b=="Z") {
            sa+=7;
            sb+=3;
        } else if (a=="B" && b=="X") {
            sa+=8;
            sb+=1;
        } else if (a=="B" && b=="Z") {
            sa+=2;
            sb+=9;
        } else if (a=="C" && b=="X") {
            sa+=3;
            sb+=7;
        } else {
            sa+=8;
            sb+=2;
        }
    }
    cout << "score of b: " << sb;
}