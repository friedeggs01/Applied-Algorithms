#include<bits/stdc++.h>
using namespace std;
int a[10001];
bool check(int v, int k) {
    for(int i=0; i<k; i++) {
        if(a[i]== v){
            return false;
        }
    }
    return true;
}
void permutation(int n, int k) {
    for(int v=1; v<=n; v++) {
        if(check(v, k)){
            a[k] = v;
            if(k == n-1) {
                for(int i=0; i<n; i++) {
                    cout << a[i] << " ";
                }
                cout << endl;
            } else {
                permutation(n, k+1);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    permutation(n, 0);
}