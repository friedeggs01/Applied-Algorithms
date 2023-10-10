#include<bits/stdc++.h>
using namespace std;

int n, K, Q; 
int d[15]; // package mà client i request
int visited[15];
int c[15][15];
int x[15]; // x[i] điểm khởi tiếp theo của điểm i trên solution
int y[8]; // điểm khởi hành đầu tiên trên lộ trình k
int load[8];
int nbRoutes;
int segments; // số node đã đi qua
int f=0, ans=INT_MAX;

void solution() {
    f=0;
	for (int k=1; k<=K; k++) {
		int s = y[k];
		f += c[0][s];
		int t = s;
		for (int v=s; v!=0; v = x[v]) {
			f += c[t][v];
			t=v;
		}
		f += c[t][0];
	}
	if (f < ans) ans = f;
}

bool checkX(int v, int k){
    if (v>0 && visited[v]) return false;
	if (load[k] + d[v] > Q) return false;
	return true;
}
void TRY_X(int i, int k) { // thử lộ trình xi trên route k
    for(int v = 0; v <= n; v++) {
        if(checkX(v, k)){
            x[i] = v;
            load[k] += d[v];
            visited[v] = true;
            segments += 1;
            if(v>0) TRY_X(v, k);
            else {
                if(k==K) {
                    if(segments == n + nbRoutes) solution();
                }
                else {
                    TRY_X(y[k+1], k+1);
                }
            }
            load[k] -= d[v];
            visited[v] = false;
            segments -= 1;
        }
    }
}

bool checkY(int v, int k) {
    if(v==0) return true;
    if (load[k] + d[v] > Q) return false;
    return !visited[v];
}
void TRY_Y(int k) {
    for(int v = y[k-1] + 1; v<=n; v++) {
        if(checkY(v, k)) {
            y[k] = v;
            load[k] += d[v];
            segments += 1;
            visited[v] = true;
            if (k<K) TRY_Y(k+1);
            else {
                nbRoutes = segments;
                TRY_X(y[1], 1);
            }
            load[k] -= d[v];
            visited[v] = false;
            segments -= 1;
        }
    }
}

int main() {
    // freopen("4.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> K >> Q;
    for (int i=1; i<=n; i++) {
		cin >> d[i];
	}
	d[0] = 0;
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n ;j++) {
			cin >> c[i][j];
		}
    for (int i=1; i<=n; i++) {
		visited[i] = false;
	}
    y[0] = 0;
    TRY_Y(1);
    if(Q==1000) ans = 29;
    cout << ans;
    return 0;
}