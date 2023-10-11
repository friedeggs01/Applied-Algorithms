#include<iostream>
using namespace std;

int BinSearch(int a[], int n, int x){
    int l = 0, r = n-1;
    while(l < r){
        if(a[(l+r)/2]>=x){
            r = (l+r)/2;
        } else {
            l = ((l+r)/2)+1;   
        }
    }
    if(a[l]==x){
        return l;
    }
    return -1;
}
int main() {
    int n, a[10001], x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> x;
    cout << BinSearch(a, n, x);
}