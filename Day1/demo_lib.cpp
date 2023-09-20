#include<bits/stdc++.h>
using namespace std;

void demostack(){
    stack<int> S;
    for(int i = 1; i <= 10; i++) S.push(i);
    while(!S.empty()) {
        int e = S.top(); S.pop();
        cout << e << " ";
    }
}
void demoqueue(){
    queue<string> Q;
    for(int i = 1; i <= 10; i++) {
        char s[10];
        sprintf(s, "e%d", i);
        string k(s);
        Q.push(s);
    }
    while(!Q.empty()) {
        string e = Q.front(); Q.pop();
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // demostack();
    demoqueue();
    return 0;

}