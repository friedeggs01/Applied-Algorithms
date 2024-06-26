// dont know the reason why it not working
#include<bits/stdc++.h>
using namespace std;

int n, m;
int dist[101][101];

void floyd() {
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    cout << 1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("2.txt", "r", stdin);
    cin >> n >> m;

    int u, v, w;
    while(m--){
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    for(int i=1; i<=n; i++) {
        dist[i][i] = 0;
    }

    cout << "Initial Distance Matrix:\n";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << dist[i][j] << " ";
        } 
        cout << endl;
    }

    floyd();

    cout << "Final Distance Matrix:\n";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << dist[i][j] << " ";
        } 
        cout << endl;
    }

    return 0;
}