#include<bits/stdc++.h>
using namespace std;
int a[10000001];
void generateBinary(int n, int k) {
    for (int i=0; i<=1; i++){
        a[k] = i;
        if(k==(n-1)) {
            for (int i = 0; i < n; i++) {
                cout << a[i];
            }
            cout << endl;
        } else {
            generateBinary(n, k+1);
        }
    }
}
int main() {
    int n; 
    cin >> n;
    generateBinary(n, 0);
}