#include<bits/stdc++.h>
using namespace std;
#define MAX 50
int n,K,Q;
int d[MAX];
int c[15][15];
int x[MAX]; // x[i] is the next point of i (i = 1,...,n), x[i] \in 
// {0,1,...,n}
int y[MAX];// y[k] is the start point of route k
int load[MAX];
int visited[MAX];// visited[i] = 1 means that client point i has been c visited
int segments;// number of segments accumulated
int nbRoutes;
int ans; // records number of solutions
int p;

pair<int, int> conflict[1001];
vector<int> r[100];
bool numberExists(const std::vector<int>& vec, int number) {
    for (const auto& element : vec) {
        if (element == number) {
            return true;  // Number found in the vector
        }
    }
    return false;  // Number not found in the vector
}
void solution(){
    ans++;
    for(int k = 1; k <= K; k++){
        int s = y[k];
        printf("route[%d]: 0 ",k);
        for(int v = s; v != 0; v = x[v]){
            printf("%d ",v);
        }
        printf("0\n");
    }
    printf("---------------------------\n");
    for(int k = 1; k <= K; k++){
        int s = y[k];
        for(int v = s; v != 0; v = x[v]){
            r[k].push_back(v);
        }
    }
    int check[K];
    for(int k=1; k<=K; k++) {
        for(int i = 0; i<p; i++){
            int client1 = conflict[i].first;
            int client2 = conflict[i].second;
            if(numberExists(r[k], client1) && numberExists(r[k], client2)){
                check[k] = 1;
                break;
            }
        }
    }

int ansmin=10000, f;
    for (int k = 1; k <= K; k++) {
        f = 0;
        if (check[k] != 1) {
            f += c[0][r[k][0]] + c[r[k][r[k].size() - 1]][0];
            for (int i = 0; i < r[k].size() - 1; i++) {
                f += c[r[k][i]][r[k][i + 1]];
            }
        }
        cout << ansmin << " " << f << endl;
        if(ansmin < f) {
            ansmin = f;
        }
    }
}

int checkX(int v,int k){
    if(v > 0 && visited[v]) return 0;
    if(load[k] + d[v] > Q) return 0;
    return 1;
}
void input(){
    scanf("%d%d%d",&n,&K,&Q);
    for(int i = 1; i <= n; i++){
        scanf("%d",&d[i]);
    }
    d[0] = 0;
    for (int i=0; i<=n; i++){
		for (int j=0; j<=n ;j++) {
			cin >> c[i][j];
		}
    }
}
void TRY_X(int s, int k){
    for(int v = 0; v <= n; v++){
        if(checkX(v,k)){
            x[s] = v;
            visited[v] = 1; load[k] += d[v]; segments++;
            if(v > 0) TRY_X(v,k);
            else{
                if(k == K){ 
                    if(segments == n+nbRoutes) solution();
                }else TRY_X(y[k+1],k+1);
            }
            segments--; load[k] -= d[v]; visited[v] = 0;
            }
        }
    }
int checkY(int v, int k){
    if(v == 0) return 1;
    if(load[k] + d[v] > Q) return 0;
    return !visited[v];
}
void TRY_Y(int k){
    for(int v = y[k-1] + 1; v <= n; v++){// 0 < y[1] < y[2] < . . . . < y[K]
        if(checkY(v,k)){
        y[k] = v;
        segments += 1;
        visited[v] = 1; load[k] += d[v];
        if(k < K){
            TRY_Y(k+1);
        }else{
            nbRoutes = segments;
            TRY_X(y[1],1);// du bo y[1],...,y[K], bat dau duyet cho diem tiep
            // theo cua y[1]
        }
        load[k] -= d[v]; visited[v] = 0;
        segments -= 1;
        }
    }
}
void solve(){
    for(int v = 1; v <= n; v++) visited[v] = 0;
    y[0] = 0;
    ans = 0;
    TRY_Y(1);
    printf("Number of solutions = %d",ans);
}
int main(){
    freopen("4.txt", "r", stdin);
    input();
    cin >> p;
    for(int i=0; i<p; i++) {
        cin >> conflict[i].first >> conflict[i].second;
    }
    solve();
    cout << ansmin;
}



