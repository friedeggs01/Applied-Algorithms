#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("2.txt", "r", stdin);
    int n, a1=0, a2=0, a3=0, a4=0, a5=0;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if(a[i]==1){
            a1++;
        } else if(a[i]==2){
            a2++;
        } else if (a[i]==3){
            a3++;
        } else if (a[i]==4){
            a4++;
        } else {
            a5++;
        }
    }
    cout << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << endl;
    if(a4>=a1){
        a5 += a4;
        a1 = 0;
        a4 = 0;
    } else {
        a5 += a4;
        a1 -= a4;
        a4 = 0;
    }
    if(a3>=a2){
        a5 += a2;
        a3 -= a2;
        a2 = 0;
        if (a3 >= a1) {
            a5 += a3;
        } else {
            a5 += a3;
            a1 -= a3;
            if(a1 % 5 == 0){
                a5 += a1 / 5;
            } else {
                a5 += (a1/5) + 1;
            }
        }
    } else {
        a5 += a2;
        a2 -= a3;
        a3 = 0;
        if(a2 == a1*2){
            a5 += a1;
        } else if (a2 > a1*2) {
            if(a2 % 2 == 0){
                a5 += a2 / 2;
            } else {
                a5 += (a2/2) + 1;
            }
        } else {
            a5 += a2 / 2;
            a1 -= a2 / 2;
            a2 = a2%2;
            if((a1+a2*2) % 5 == 0){
                a5 += a1 / 5;
            } else {
                a5 += (a1/5) + 1;
            }
        }
    }
    cout << a5;
}