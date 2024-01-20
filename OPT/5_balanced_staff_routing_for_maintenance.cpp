#include<bits/stdc++.h>
using namespace std;

int n, k, t[1001][1001], d[1001],f[1001][1001];
vector<int> r[1001];

int calculate_fitness(vector<int> path){
    int res=0;
    res += f[0][path[0]];
    res += d[path[0]];
    // cout << res << endl;
    int i = 0;
    for(i = 0; i<path.size()-1; i++) {
        res += d[path[i+1]];
        res += f[path[i]][path[i+1]];
        // cout << res << endl;
    }
    res += f[path[i]][0];
    // cout << res << endl;
    return res;
}

vector<int> randomly_swap(vector<int> path){
    // Choose an index (for example, i = 42)
    int i = 42;

    // Get the size of the vector r[i]
    size_t size = path.size();

    // Generate two random indices within the size of the vector
    size_t index1 = std::rand() % size;
    size_t index2 = std::rand() % size;

    // Swap the elements at the randomly chosen indices
    std::swap(path[index1], path[index2]);
    return path;
}


int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("5.txt", "r", stdin);
    cin >> n >> k;
    bool visited[n+1];
    memset(visited, false, sizeof(visited));
    visited[n] = false;
    // cout << visited[5];
    visited[0] = true;
    for(int i=1; i<=n; i++) {
        cin >> d[i];
    }
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            cin >> t[i][j];
            f[i][j] = t[i][j];
        }
        t[i][i] = INT_MAX;
    }
    for(int i=1; i<=k; i++) {
        int* minElement = min_element(t[0], t[0] + n);
        int j = minElement - t[0];
        if(!visited[j]) {
            visited[j] = true;
            r[i].push_back(j);
            t[0][j] = INT_MAX;
        }
        // cout << r[i][0] << endl;
    }
    while(count(visited, visited + n, false) > 0){
        for(int i=1; i<=k; i++) {
            // cout << "visited[5]: " << visited[5]<< endl;
            // cout << "worker: " << i << " r[i][r[i].size()-1] " << r[i][r[i].size()-1] << endl;
            int* minElement = min_element(t[r[i][r[i].size()-1]], t[r[i][r[i].size()-1]] + n+1);
            int j = minElement - t[r[i][r[i].size()-1]];
            t[r[i][r[i].size()-1]][j] = INT_MAX;
            if(j == 0) continue;
            // cout << j << endl;
            if(!visited[j]) {
                visited[j] = true;
                r[i].push_back(j);
            }
        }
    }
    cout << k << endl;
    for(int i=1; i<=k; i++) {
        cout << r[i].size()+2 << endl;
        cout << 0 << " ";
        for(auto j : r[i]) {
            cout << j << " ";
        }
        cout << 0 << endl;
    }
    for(int i=1; i<=k; i++) {
        cout << "i: " << i << endl;
        int cnt = 0;
        while(true) {
            cnt++;
            int res = calculate_fitness(r[i]);
            cout << res;
            vector<int> new_path = randomly_swap(r[i]);
            int res2 = calculate_fitness(new_path);
            if(cnt >= 10 || res2 < res){
                r[i] = new_path;
                cout << res2 << endl;
                break;
            }
        }
    }
    cout << k << endl;
    for(int i=1; i<=k; i++) {
        cout << r[i].size()+2 << endl;
        cout << 0 << " ";
        for(auto j : r[i]) {
            cout << j << " ";
        }
        cout << 0 << endl;
    }
}