#include<bits/stdc++.h>
#pragma GCC optimize("03")
#pragma GCC target ("sse4")
using namespace std;
int li = 0;
int n, m, a[20][20];
int c[20];
int sol[100], load[100], min_load = INT_MAX;
vector<int> course_pre[50];
bool inline check(int v, int k) {
	for(auto &i: course_pre[k]){
		// cout << "i: " << i << endl;
		if(v < sol[i]) return false;
	}
	return true;
}

void inline TRY(int k) {
	// cout << "k: "<< k << endl;
	for(int v = 0; v<m; v++){
		// cout << "v: " << v << endl;
		if(check(v,k)) {
			sol[k] = v;
			load[v] += c[k];
			if(k==(n-1)) {
				int loads = *max_element(load, load+n);
				if (loads < min_load){
					min_load = loads;
					// cout << min_load << endl;
				}
			} else {
				// if(load[v] < min_load) {
				// 	TRY(k+1);
				// }
				TRY(k+1);
			}
			load[v]-= c[k];
		}
	}
}

int main () {
    // freopen("2.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> c[i];

	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> a[i][j];
			if(a[i][j] == 1){
				course_pre[j].push_back(i);
			}
		}
	}
	TRY(0);
	cout << min_load;
	return 0;	
}
