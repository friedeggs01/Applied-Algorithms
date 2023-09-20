#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long int a, b;
    cin >> a >> b;
    unsigned long long int a1 = a/10;
    int a2 = a%10;
    unsigned long long int b1 = b/10;
    int b2 = b%10;
    unsigned long long int c1 = a1 + b1;
    int c2 = a2 + b2;
    if (c2 >= 10) {
        c1 += a1 + b1 + 1;
    }
    c2 = c2 % 10;
    if (c1 != 0) {
        cout << c1 <<c2;
    } else {
        cout << c2;
    }
    
    return 0;
}