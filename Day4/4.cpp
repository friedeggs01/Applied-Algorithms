#include<bits/stdc++.h>
using namespace std;

int n, m, c[100][100], sol[101], cost=0, min_cost = 10000, countt = 0;
bool visited[100]; // for check if this city is visited

void TRY(int k) {
	for(int v = 1; v < n; v++){
		if(!visited[v]) {
            // assign next position
			sol[k] = v;
			visited[v] = true;
			cost += c[sol[k-1]][sol[k]];
			if(k==n-1) {
				cost += c[sol[k]][0];
				if (cost <= m){
					countt++;
				}
				cost -= c[sol[k]][0];
			} else {
				if(cost < m) {
					TRY(k+1);
				}
			}
            // remember to update again
			visited[v] = false;
			cost -= c[sol[k-1]][v];
			
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i< n; i++) {
		for(int j=0; j<n; j++) {
			cin >> c[i][j];
		}
	}
	for(int i=0; i<n; i++) {
		visited[i] = false;
	}
    // always start from city 0
	sol[0] = 0; visited[0] = true;

	TRY(1);
	cout << countt;
	return 0;
}
