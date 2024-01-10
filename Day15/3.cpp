#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
    int n;
    cin >> n;

    int steps = 0;
    while (n != 0) {
        if (n >= 5 && (n - 5) < (n + 2)) {
            n -= 5;
        } else {
            n += 2;
        }
        steps++;
    }

    cout << steps << endl;

    return 0;
}