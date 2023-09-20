#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

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
void demopriorityqueue(){
    // ưu tiên phần tử có khóa lớn nhất ra trước
    priority_queue<int> pq;
    pq.push(4);
    pq.push(9);
    pq.push(2);
    pq.push(5);
    while(!pq.empty()) {
        int e = pq.top(); pq.pop();
        cout << "pq.pop(" << e << ")" << endl;
    }
    cout << endl;
    //  ưu tiên phần tử có khóa nhỏ nhất ra trước
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    PQ.push(make_pair(4, -40));
    PQ.push(make_pair(2, -20));
    PQ.push(make_pair(9, -90));
    PQ.push(make_pair(5, -50));
    while(!PQ.empty()) {
        pii e = PQ.top(); PQ.pop();
        cout << "PQ.pop(" << e.first  << "," << e.second << ")" << endl;
    }
}
void demomap(){
    map<int, int> M;
    M[3] = 786;
    M[2] = 2;
    M[10] = 7;
    M[100000] = 23;
    int a = 1;
    cout << M[a] << endl;

    map<string, int> M1;
    M1["abc"] = 1;
    M1["def"] = 10;
    M1["xyz"] = 100;
    string k = "xyz";
    cout << "M1{" << k << "} = " << M1[k] << endl;

    for(map<string, int>::iterator p = M1.begin(); p != M1.end(); p++) {
        cout << "map(" << p->first << "," << p->second << ")" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // demostack();
    // demoqueue();
    // demopriorityqueue();
    demomap();
    return 0;

}