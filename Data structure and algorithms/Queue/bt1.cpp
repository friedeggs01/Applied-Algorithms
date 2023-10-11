//bài toán rót nước
// có một bể chứa nước vô hạn
// có 2 cốc với dung tích là a, b (nguyên dương) lít
// tìm cách đong đúng c (nguyên dương) lít nước

#include<bits/stdc++.h>

using namespace std;

struct State{
    int x;
    int y;
    string msg; //action to generate current state
    State* p;  //pointer to state generating current state
};
bool visited[10001][10001];
void initVisted() {
    for(int i=0; i<10001; i++){
        for(int j=0; j<10001; j++){
            visited[i][j] = false;
        }
    }
}
queue<State*> Q;
list<State*> L;
State *target;
int a, b, c;
bool reachTarget(State* S){
    return S->x == c || S->y == c || S->x + S->y == c;
}
void markVisit(State *S){
    visited[S->x][S->y] = true;
}
void freeMemory() {
    list<State*>:: iterator it;
    for(it=L.begin(); it!=L.end(); it++){
        delete *it;
    }
}

bool genMove1Out(State* S){
    if(visited[0][S->y]) return false;
    State* newS = new State;
    newS->x = 0;
    newS->y = S->y;
    newS->msg = "Do het nuoc o coc 1 ra ngoai";
    newS->p = S;
    Q.push(newS); markVisit(newS);
    L.push_back(newS);
    if(reachTarget(newS)){
        target = newS;
        return true;
    }
    return false;
}
bool genMove2Out(State* S){
    if(visited[S->x][0]) return false;
    State* newS = new State;
    newS->x = S->x;
    newS->y = 0;
    newS->msg = "Đổ hết nước ở cốc 2 ra ngoài";
    newS->p = S;
    Q.push(newS); markVisit(newS);
    L.push_back(newS);
    if(reachTarget(newS)){
        target = newS;
        return true;
    }
    return false;
}
bool genMove1Full2(State* S) {
    if(S->x+S->y < b)  return false;
    if(visited[S->x + S->y - b][b]) return false;
    State* newS = new State;
    newS->x = S->x + S->y - b;
    newS->y = b;
    newS->msg = "Đổ nước từ cốc 1 vào đầy cốc 2";
    newS->p = S;
    Q.push(newS); markVisit(newS);
    L.push_back(newS);
    if(reachTarget(newS)){
        target = newS;
        return true;
    }
    return false;

}
bool genMove2Full1(State* S){
    if(S->x+S->y < a)  return false;
    if(visited[a][S->x + S->y - a]) return false;
    State* newS = new State;
    newS->x = a;
    newS->y = S->x + S->y - a;
    newS->msg = "Đổ nước từ cốc 2 vào đầy cốc 1";
    newS->p = S;
    Q.push(newS); markVisit(newS);
    L.push_back(newS);
    if(reachTarget(newS)){
        target = newS;
        return true;
    }
    return false;
}
bool genMoveAll12(State* S){
    if(S->x+S->y > b) return false;
    if(visited[0][S->x + S->y]) return false;
    State* newS = new State;
    newS->x = 0;
    newS->y = S->x + S->y;
    newS->msg = "Đổ hết nước từ cốc 1 sang cốc 2";
    newS->p = S;
    Q.push(newS); markVisit(newS);
    L.push_back(newS);
    if(reachTarget(newS)){
        target = newS;
        return true;
    }
    return false;
}
bool genMoveAll21(State* S){
    if(S->x+S->y>a) return false;
    if(visited[S->x+S->y][0]) return false;
    State* newS = new State;
    newS->x = S->x+S->y;
    newS->y = 0;
    newS->msg = "Đổ hết nước từ cốc 2 sang cốc 1";
    newS->p = S;
    Q.push(newS); markVisit(newS);
    L.push_back(newS);
    if(reachTarget(newS)){
        target = newS;
        return true;
    }
    return false;
}
bool genMoveFill1(State* S){
    if(visited[a][S->y]) return false;
    State* newS = new State;
    newS->x = a;
    newS->y = S->y;
    newS->msg = "Đổ đầy nước vào cốc 1";
    newS->p = S;
    Q.push(newS); markVisit(newS);
    L.push_back(newS);
    if(reachTarget(newS)){
        target = newS;
        return true;
    }
    return false;
}
bool genMoveFill2(State* S){
    if(visited[S->x][b]) return false;
    State* newS = new State;
    newS->x = S->x;
    newS->y = b;
    newS->msg = "Đổ đầy nước vào cốc 2";
    newS->p = S;
    Q.push(newS); markVisit(newS);
    L.push_back(newS);
    if(reachTarget(newS)){
        target = newS;
        return true;
    }
    return false;
}
void solve(){
    initVisted();
    
    State* S = new State;
    S->x=0; S->y=0; S->p=NULL;
    Q.push(S); markVisit(S);
    while(!Q.empty()){
        State* S = Q.front();
        if(genMove1Out(S)) break;
        if(genMove2Out(S)) break;
        if(genMove1Full2(S)) break;
        if(genMove2Full1(S)) break;
        if(genMoveAll12(S)) break;
        if(genMoveAll21(S)) break;
        if(genMoveFill1(S)) break;
        if(genMoveFill2(S)) break;
    }
}
int main() {
    cin >> a >> b >> c;
    target = NULL;
    solve();
    cout << target;
    freeMemory();
}