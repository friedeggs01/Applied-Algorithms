#include <bits/stdc++.h> 
using namespace std; 
#define int long long 
const int MAX=2e5+8, m=1e9+7, maxn=1e6+9; 
int n, a[MAX], b[MAX]; 
vector<int> expression; 
main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    // freopen("2.txt", "r", stdin); 
    cin>>n; 
    for(int i=0;i<n;i++) { 
        cin>>a[i]; 
    } 
    for(int i=1;i<n;i++) { 
        cin>>b[i]; 
    } 
    expression.push_back(a[0]); 
    for(int i=1;i<n;i++) { 
        if(b[i]==0) 
        expression.push_back(-a[i]); 
        if(b[i]==1) expression.push_back(a[i]);
        if(b[i]==2) expression.back() = expression.back()*a[i]%m; 
    } 
    int ans = 0; 
    for(int i:expression) {ans = (ans+i+m)%m;}
    cout<<ans; }