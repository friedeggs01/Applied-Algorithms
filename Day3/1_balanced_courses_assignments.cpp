#include<bits/stdc++.h>
#pragma GCC optimize("03")
#pragma GCC target ("sse4")
using namespace std;
int m, n, k;
int sol[100] = {-1};
int load[100];
int teaching[101][101];
vector<int> by_teacher[50];
int size_teaching[101];
bool conflict[100][100];
int min_load = 1000;
bool inline check(int v, int k) {
    for(int i = 0; i < size_teaching[v]; ++i) {
        if(conflict[teaching[v][i]][k]) {
            return false;
        }
    }
	return true;
}

// each subject for which teacher?
void inline TRY(int k) {
	for(auto &v: by_teacher[k]){
		if(check(v,k)) {
			sol[k] = v;
			load[v]++;

			teaching[v][size_teaching[v]++] = k;
			if(k==n) {
				int loads = *max_element(load, load+n);
				if (loads < min_load){
					min_load = loads;
				}
				// find maximum subject that a teacher have to teach
			} else {
				if(load[v] < min_load) {
					TRY(k+1);
				}
			}
			load[v]--;
            sol[k] = -1;
			size_teaching[v]--;
		}
	}
}

int main () {
    // freopen("1.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
	cin >> m >> n;
	for (int i=0; i<m; i++) {
		int temp;
		cin >> temp;
		for(int j = 0; j < temp; j++){
			int subject;
			cin >> subject;
			by_teacher[subject].push_back(i);
		}
	}
	int cf;
	cin >> cf;
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			conflict[i][j] = false;
			conflict[j][i] = false;
		}
	}
	for(int i=0; i<cf; i++) {
		int a, b;
		cin >> a >> b;
		conflict[a][b] = true;
		conflict[b][a] = true;
	}
	TRY(1);
	cout << min_load;
	return 0;	
}
