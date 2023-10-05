#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= 999; i++) {
        if(n*i < 100 || n*i > 999) {
            continue;
        } else {
            cout << (n*i) << " ";
        }
    }
}