#include<bits/stdc++.h>
using namespace std;

int n, a[10001];

int fib(int n){
    if (n == 0 || n == 1) {
        a[n] = n;
    } else {
        a[n] = fib(n-1) + fib(n-2);
    }
    return a[n];
}

int main() {
    cin >> n;
    cout << fib(n-1);
}