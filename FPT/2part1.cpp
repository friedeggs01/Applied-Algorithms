#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("2.txt", "r", stdin);
    int al, ar, bl, br;
    int cnt=0;
    int n=1000;
    while(n--){
        scanf("%d-%d,%d-%d", &al,&ar,&bl,&br);
        // cout << al << " " << ar << " " << bl << " " << br << endl;
        if(al<=bl && ar >= br) {
            cnt++;
        } else if (al>=bl && ar<=br){
            cnt++;
        }
        // cout << cnt << endl;
    }
    cout << cnt;
}