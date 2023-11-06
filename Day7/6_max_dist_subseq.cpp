// expect dist = mid if true try(mid+1) else try(mid/2)

#include<bits/stdc++.h>
using namespace std;

int t, n, c;
unsigned int x[100001];

bool isFeasible(int mid, int n){
    int pos = x[0]; 
  
    int elements = 1; 
  
    for (int i = 1; i < n; i++) { 
        if (x[i] - pos >= mid) { 
            pos = x[i]; 
            elements++; 
  
            if (elements == c) 
                return true; 
        } 
    } 
    return 0; 
}

int solve(){
    int ans=-1;
    int left=1, right=x[n-1];
    while(left<right){
        int mid = (left+right)/2;
        if(isFeasible(mid, n)){
            ans = max(ans, mid);
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("6.txt", "r", stdin);
    cin >> t;
    while(t--){
        cin >> n >> c;
        for(int i=0; i<n; i++){
            cin >> x[i];
        }
        sort(x, x+n);
        cout << solve() << endl;
    }
}