#include<bits/stdc++.h>
using namespace std;

int m, n, Q[1001][1001], d[1001][1001], q[1001], q_have[1001];
vector<int> road;

bool not_enough(){
    for(int i=1; i<=n; i++) {
        if(q_have[i] < q[i]){
            // cout << "true " << q_have[i] << " " << q[i] << endl;
            return true;
        }
    }
    // cout << "false" << endl;
    return false;
}
int cal_fitness(vector<int> path){
    int cur = 0;
    int res = 0;
    for(auto i : path){
        res += d[cur][i];
        cur = i;
    }
    res += d[cur][0];
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("4.txt", "r", stdin);
    cin >> n >> m;
    cout << "product: " << n << ", shelf: " << m << endl;
    bool visited[m];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> Q[i][j];
        }
    }

    for (int i = 0; i <= m; ++i) {
        visited[i] = false;
        for (int j = 0; j <= m; ++j) {
            cin >> d[i][j];
        }
        d[i][i] = INT_MAX;
    }

    for (int i = 1; i <= n; ++i) {
        cin >> q[i];
        q_have[i] = 0;
    }

    visited[0] = true;
    int prev = 0;
    while(not_enough()){
        int* minElement = min_element(d[prev], d[prev]+m);
        int j = minElement - d[prev];
        if(visited[j] == false) {
            visited[j] = true;
            prev = j;
            // cout << j << " ";
            road.push_back(j);
            for(int i=1; i<=n; i++) {
                q_have[i] += Q[i][j];
                // cout << q_have[i] << " ";
            }
            // cout << endl;
        } else {
            d[prev][j] = INT_MAX;
        }
    }
    // cout << "done" << endl;
    cout << road.size() << endl;
    for (auto i : road) {
        cout << i << " ";
    }
    // cout << endl << cal_fitness(road);
    return 0;
}
