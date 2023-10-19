#include <bits/stdc++.h>

using namespace std;
int n, m, h, ans[201];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ans[0] = 1;
    for(int i=1; i<=200;i++) {
        ans[i] = (ans[i-1]*256)%m;
    }
    string s;
    while(n--){
        cin >> s;
        int l = s.length();
        h=0;
        for(int j=0; j<l; j++){
            h += (s[j]* ans[s.length()-j-1]%m)%m ;
        }
        printf("%d\n", h%m);
    }
    return 0;
}
