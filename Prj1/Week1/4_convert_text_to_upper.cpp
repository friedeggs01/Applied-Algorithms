#include<bits/stdc++.h>
using namespace std;

int main() {
    char charr[100001];
    int i = 0;

    // Read characters until end of input
    while (cin.get(charr[i])) {
        if (charr[i] >= 'a' && charr[i] <= 'z') {
            charr[i] -= 32;
        }
        cout << charr[i];
        i++;
    }

    return 0;
}