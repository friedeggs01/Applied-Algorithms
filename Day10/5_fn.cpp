#include<bits/stdc++.h>
using namespace std;

int n;
unsigned long long int f[1001];
unsigned long long int s[3][1001];
int q = 1000000007;

int main() {
    cin >> n;
    f[0] = 1;
    f[1] = 3;
    s[0][1] = 1;
    s[1][1] = 1;
    s[2][1] = 1; 
    for(int i=2; i<=n; i++) {
        s[0][i] = (s[1][i-1] + s[2][i-1]);
        s[1][i] = s[0][i-1] + s[2][i-1];
        s[2][i] = f[i-1];
        f[i] = s[0][i] + s[1][i] + s[2][i];
        f[i] %= q;
    }
    cout << f[n] % q;
}