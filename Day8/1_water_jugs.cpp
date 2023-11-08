#include<bits/stdc++.h>
using namespace std;

int a, b, c;

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

    State s1(a, s.y, s.step+1);
    ns.push_back(s1);

    State s2(s.x, b, s.step+1);
    ns.push_back(s2);

    State s3(0, s.y, s.step+1);
    ns.push_back(s3);

    State s4(s.x, 0, s.step+1);
    ns.push_back(s4);

    // 1->2
    if(s.x+s.y >=b) {
        State s5(s.x+s.y-b, b, s.step+1);
        ns.push_back(s5);
    } else {
        State s6(0, s.x+s.y, s.step+1);
        ns.push_back(s6);
    }

    // 2->1
    if(s.x+s.y >= a) {
        State s7(a, s.x+s.y-a, s.step+1);
        ns.push_back(s7);
    } else {
        State s8(s.x+s.y, 0, s.step+1);
        ns.push_back(s8);
    }

    return ns;
}

int minStep(){
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            visited[i][j] = false;
        }
    }
    queue<State> states;
    State start = State(0, 0, 0);
    states.push(start);
    visited[0][0] = true;

    while(!states.empty()) {
        State current = states.front();
        states.pop();

        vector<State> neighborhood = get_neighborhood(current);
        for (auto i=0; i < neighborhood.size(); i++) {
            State ns = neighborhood[i];
            if(ns.x == c || ns.y == c) return ns.step;
            if(!visited[ns.x][ns.y]) {
                states.push(ns); visited[ns.x][ns.y] = true;
            }
        }
    }
    return -1;
}

int main() {
    freopen("1.txt", "r", stdin);
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cin >> a >> b >> c;
    cout << minStep();
    return 0;
}
