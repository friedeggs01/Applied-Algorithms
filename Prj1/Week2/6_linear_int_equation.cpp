#include<bits/stdc++.h>
using namespace std;

int n, m, sol[1001], sum=0;

bool check(int v, int k) {
    if(sum+v > m) {
        return false;
    }
    return true;
}

void TRY(int k) {
    for(int v = 1; v <= m-n+1;v++) {
        if(check(v, k)) {
            sol[k] = v;
            sum+=v;
            if(k==(n-1) && sum == m) {
                for(int i=0; i<n; i++) {
                    cout << sol[i] << " ";
                }
                cout << endl;
            } else {
                TRY(k+1);
            }
            sum -= v;
        }
    }
}

int main () {
    cin >> n >> m;
    TRY(0);
}