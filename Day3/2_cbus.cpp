#include<bits/stdc++.h>
using namespace std;

int n, c[102][101], sol[101], cost_min = 1000, seats, cmin = 1000, cost =0;
bool visited[100];

bool check(int v, int k) {
	if(visited[v]) return false;
	if(v<=n) {
		return seats > 0;
	}
	if(v>n) {
		if(!visited[v-n]) return false;
	}
	return true;
}

void TRY(int k) {
	for(int v = 1; v< 2*n+1; v++){
		if(check(v, k)){
			sol[k] = v;
			visited[v] = true;
			cost += c[sol[k-1]][v];
			if(v<=n) seats--;
			else seats++;
			
			if(k== 2*n) {
				if(cost+c[sol[2*n]][sol[0]] < cost_min){
					cost_min = cost + c[sol[2*n]][sol[0]];
				}	
//				for(int i=0; i<2*n+1; i++) {
//					cout << sol[i] << " ";
//				}	
//				cout << endl;
//				cout << cost_min << endl;
			} else {
				if(cost +cmin*(2*n+1-k) < cost_min) {
					TRY(k+1);
				}
			}
			cost -= c[sol[k-1]][v];
			visited[v] = false;
			if(v<=n) seats++;
			else seats--;
		}
	}
}

int main() {
	cin >> n >> seats;
	for(int i = 0; i< 2*n+1; i++) {
		for(int j=0; j<2*n+1; j++) {
			cin >> c[i][j];
			if(i!=j && c[i][j] < cmin){
				cmin = c[i][j];
			}
		}
	}
	for(int i = 0; i < 2*n+1; i++) {
		visited[i] = false;
	}
	sol[0] = 0; visited[0] = true;
	TRY(1);
	cout << cost_min;
	return 0;
}
