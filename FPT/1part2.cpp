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
        if (b=="X" && a=="A") {
            sb+=3;
        } else if (b=="X" && a=="B"){
            sb+=1;
        } else if (b=="X" && a=="C"){
            sb+=2;
        } else if (b=="Y" && a=="A") {
            sb+=4;
        } else if (b=="Y" && a=="B"){
            sb+=5;
        } else if (b=="Y" && a=="C"){
            sb+=6;
        } else if (b=="Z" && a=="A") {
            sb+=8;
        } else if (b=="Z" && a=="B"){
            sb+=9;
        } else if (b=="Z" && a=="C"){
            sb+=7;
        }
    }
    cout << "score of b: " << sb;
}