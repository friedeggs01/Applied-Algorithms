#include<iostream>
using namespace std;
int BinSearch(int a[], int n, int x){
    int l = 0, r = n-1;
    while(l < r){
        if(a[(l+r)/2] < x){
            l = ((l+r)/2)+1;
        } else {
            r = (l+r)/2;
        }
    }
    if(a[l] == x){
        return l;
    } else {
        return -1;
    }
}
void printArray(int a[], int l, int r){
    for(int i = l; i <= r; i++){
        cout << a[i] << " ";
    }
}
bool solve(int a[], int b[], int n, int s){
    b[0] = a[0];
    for(int i = 1; i < n; i++){
        b[i] = b[i-1] + a[i];
    }
    for(int i = 0; i < n; i++){
        if(b[i] == s){
            printArray(a, 0, i);
            return true;
        }
        if(b[i] > s){
            int l = BinSearch(b, n, b[i]-s);
            if(l != -1){
            printArray(a, l+1, i);
            return true;
            }
        }
    }
}

int main() {
    int a[10001], b[10001], n, s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> s;
    bool k = solve(a, b, n, s);
    if(!k){
        cout << -1;
    }
}