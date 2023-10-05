#include<bits/stdc++.h>
using namespace std;
int sol[1001], n;
bool check(int v, int k) {
    for(int i=0; i<k ;i++) {
        if(sol[i] == v) {
            return false;
        }
    }
    return true;
}
void TRY(int k){
    for(int v = 1; v<=n; v++){
        if(check(v, k)){
            sol[k] = v;
            if(k==(n-1)) {
                for(int i=0; i<n; i++) {
                    cout << sol[i] << " ";
                }
                cout << endl;
            } else {
                TRY(k+1);
            }
        }
    }
}
int main( ){
    cin >> n;
    TRY(0);
}