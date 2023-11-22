#include<bits/stdc++.h>
using namespace std;

int t, n, f;
double a[10001], pi = 3.1416;

bool check(double mid){
    int sum=0;
    for(int i=1; i<=n; i++) {
        sum += int(a[i]/mid);
    }
    if(sum >= f+1) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cin >> t;
    while(t--){
        cin >> n >> f;
        double low, high, mid, ans = -1, v=0;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            a[i] = a[i]*a[i]*pi;
            v+=a[i];
        }
        low = 0;
        high = v/(f+1);
        while(high-low>0.000001){
            mid = (low+high)/2;
            if(check(mid)){
                ans = mid;
                low = mid;
            } else{
                high = mid;
            }
        }
        cout << ans << endl;
        
    }
}