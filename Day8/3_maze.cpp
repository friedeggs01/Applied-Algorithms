#include<bits/stdc++.h>
using namespace std;

int n, m, r, c;

struct State{
    int x;
    int y;
    int step;

    State(int _x, int _y, int _step) {
        x = _x; y = _y; step = _step;
    }
};
bool visited[1000][1000];

vector<State> get_neighborhood(State s) {
    vector<State> ns;

    if(s.y < m) {
        State s1(s.x, s.y+1, s.step+1);
        ns.push_back(s1);
    }

    if(s.x < n) {
        State s2(s.x+1, s.y, s.step+1);
        ns.push_back(s2);
    }

    if(s.y >= 0) {
        State s3(s.x, s.y-1, s.step+1);
        ns.push_back(s3);
    }
    
    if(s.x >= 0) {
        State s4(s.x-1, s.y, s.step+1);
        ns.push_back(s4);
    }
    return ns;
}

int minStep(){

    queue<State> states;
    State start = State(r-1, c-1 ,0);
    states.push(start);
    visited[r-1][c-1] = true;

    while(!states.empty()) {
        State current = states.front();
        states.pop();

        vector<State> neighborhood = get_neighborhood(current);
        for (auto i=0; i < neighborhood.size(); i++) {
            State ns = neighborhood[i];
            if(ns.x == n || ns.y == m || ns.x < 0 || ns.y < 0) return ns.step;
            if(!visited[ns.x][ns.y]) {
                states.push(ns); visited[ns.x][ns.y] = true;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("3.txt", "r", stdin);
    cin >> n >> m >> r >> c;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            if(temp == 1){
                visited[i][j] = true;
            } else {
                visited[i][j] = false;
            }
        }
    }
    cout << minStep();
    return 0;
}