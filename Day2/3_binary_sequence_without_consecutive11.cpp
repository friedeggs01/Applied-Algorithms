#include<bits/stdc++.h>
using namespace std;
int a[25];
bool check(int v, int k) {
    if (k > 0 && a[k-1] == 1 && v == 1) {
        return false;
    } // comment this if want to print all possible solution binary (example 1)
    return true;

}
void generateBinary(int n, int k) {
    for (int v=0; v<=1; v++){
        if(check(v, k)) {
            a[k] = v;
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
}
int main() {
    int n; 
    cin >> n;
    generateBinary(n, 0);
}