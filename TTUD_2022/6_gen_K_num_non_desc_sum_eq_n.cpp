#include<bits/stdc++.h>
using namespace std;
int a[41];
int sum = 0;
int N, K;
bool check(int v, int k){
    if(sum+v > N) {
        return false;
    } else if (k >= 1){
        if(v < a[k-1]) return false;
    }
    return true;
}
void TRY(int k){
    for(int v=1; v<=N-K+1; v++) {
        if(check(v, k)) {
            sum += v;
            a[k] = v;
            if(k==K-1 && sum==N) {
                for(int i=0; i<K; i++) {
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
    cin >> K >> N;
    TRY(0);
}