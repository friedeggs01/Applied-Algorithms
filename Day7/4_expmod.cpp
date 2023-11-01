#include<iostream>
using namespace std;

unsigned long long int m = 1e9+7;

int expmod(unsigned long long int a, unsigned long long int b){
    if (b == 0) return 1;
    unsigned long long int t = expmod(a, b/2);
    t = (t*t) % m;
    if (b%2 != 0) return (((a % m)* t) % m);
    return t % m;
}

int main() {
    freopen("4.txt", "r", stdin);
    unsigned long long int a, b;
    cin >> a >> b;
    cout << expmod(a, b);
}