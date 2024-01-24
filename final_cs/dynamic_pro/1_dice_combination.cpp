#include<bits/stdc++.h>
using namespace std;
#define MOD 10000007
int n, f[10001];

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cin >> n;
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    for(int s=1; s<=n; s++){
        for(int j=1; j<=6; j++) {
            if(j<=s){
                f[s] = f[s] + f[s-j];
            }
        }
        // cout << f[s] << endl;
    }
    cout << f[n];
}