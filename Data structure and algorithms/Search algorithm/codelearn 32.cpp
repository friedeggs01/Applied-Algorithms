#include<iostream>
using namespace std;

int search(int n, int a[], int x){
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            return i;
        }
    }
    return -1;
}
int main() {
    int n, a[100], x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> x;
    cout << search(n , a, x);
}