#include <bits/stdc++.h>
using namespace std;
#define N 1001
struct State{
	int x, y;
	int step;
	string action;
	State* parent;

	State(int _x, int _y, int _step, string _action, State* p){
		x = _x; y = _y; step = _step;
		action = _action; parent = p;
	}
};
int a,b,c;
bool visited[N][N];

vector<State*> getNeighborhood(State* s){
	vector<State*> ns;
	// fill jug 1
    State* s1 = new State(a,s->y,s->step+1,"fill_1",s);
    ns.push_back(s1);

    // fill jug 2
    State* s2 = new State(s->x,b,s->step+1,"fill_2",s);
    ns.push_back(s2);

    // empty jug 1
    State* s3 = new State(0,s->y,s->step + 1,"empty_1",s);
    ns.push_back(s3);

    // empty jug 2
    State* s4 = new State(s->x,0,s->step+1,"empty_2",s);
    ns.push_back(s4);

    // 1-> 2
    if(s->x + s->y >= b){
        State* s5 = new State(s->x+s->y - b,b,s->step+1,"1->2",s);
        ns.push_back(s5);
    }else{
        State* s6 = new State(0,s->x+s->y,s->step+1,"1->2",s);
        ns.push_back(s6);
    }
    // 2 -> 1
    if(s->x+s->y >= a){
        State* s7 = new State(a,s->x+s->y-a,s->step+1,"2->1",s);
        ns.push_back(s7);
    }else{
        State* s8 = new State(s->x+s->y,0,s->step+1,"2->1",s);
        ns.push_back(s8);
    }
	return ns;
}
State* solve(){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			visited[i][j] = false;
	queue<State*> Q;
	State* start=  new State(0,0,0,"",NULL);
	State* target = NULL;
	Q.push(start);
	visited[0][0] = true;
	while(!Q.empty()){
		State* s = Q.front(); Q.pop();
		vector<State*> neighborhood = getNeighborhood(s);
		for(int i = 0; i < neighborhood.size(); i++){
			State* ns = neighborhood[i];
			if(ns->x == c || ns->y == c){
					target = ns;
					return target;
			}
			if(!visited[ns->x][ns->y]){
				Q.push(ns); visited[ns->x][ns->y] = true;
			}
		}
	}
	return NULL;
}
int main(){
    freopen("1.txt", "r", stdin);
	cin >> a >> b >> c;
	State* res = solve();
	cout << res->step << endl;
	State* p = res;
	stack<State*> path;
	while(p != NULL){
		path.push(p);
		p = p->parent;
	}
	while(!path.empty()){
		State* p = path.top(); path.pop();
		cout << p->action << " state (" << p->x << "," << p->y << ")" << endl;
	}
	return 0;
}
