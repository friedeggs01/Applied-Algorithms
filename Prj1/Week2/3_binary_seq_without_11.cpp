#include<bits/stdc++.h>
using namespace std;
int sol[1001], n;
bool check(int v, int k) {
    if(sol[k-1] == 1 && v == 1){
        return false;
    }
    return true;
}
void TRY(int k){
    for(int v = 0; v<2; v++){
        if(check(v, k)){
            sol[k] = v;
            if(k==(n-1)) {
                for(int i=0; i<n; i++) {
                    cout << sol[i];
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