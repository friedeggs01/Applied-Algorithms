#include<bits/stdc++.h>
using namespace std;
int a[18];
int sum = 0;
int n, M;
bool check(int v, int k){
    if(sum+v > M) {
        return false;
    }
    return true;
}
void TRY(int k){
    for(int v=1; v<=M-n+1; v++) {
        if(check(v, k)) {
            sum += v;
            a[k] = v;
            if(k==n-1 && sum==M) {
                for(int i=0; i<n; i++) {
                    cout << a[i] << " ";
                } 
                cout << endl;
            } else {
                TRY(k+1);
            }
            sum -= v;
        }
    }
}
int main() {
    cin >>n>>M;
    TRY(0);
}