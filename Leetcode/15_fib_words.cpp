#include<bits/stdc++.h>
using namespace std;

int n;
string fb[1001];


int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cin >> n;
    fb[0] = '0';
    fb[1] = '1';
    string s1;
    cin >> s1;
    for(int i = 2; i <= n; i++) {
        fb[i] = fb[i-1];
        fb[i] += fb[i-2];
    }
    cout << fb[n] << endl;
    
    int count = 0;
    size_t pos = 0;
    while ((pos = fb[n].find(s1, pos)) != string::npos) {
        count++;
        pos += s1.length();
    }
    cout << count;
}