#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> sol(1001);
vector<int> best(1001);
int c[1001][1001];
int d[1001][1001];

int compute(vector<int>& a){
    int fitness = d[0][a[1] - 1];
    for(int i=1; i< n; i++) {
        fitness += d[a[i]-1][a[i+1]-1];
    }
    fitness += d[a[n-1]-1][0];
    return fitness;
}

int main() {
    freopen("4.txt", "r", stdin);
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cin >> n;
    cout << n << endl;
    bool visited[n];
    for(int i=0; i<n; i++) {
        visited[i] = false;
        for(int j=0; j<n; j++) {
            cin >> c[i][j];
            if(i == j) {
                c[i][j] = INT_MAX;
            }
            d[i][j] = c[i][j];
        }
    }

    // cout << 1 << " ";
    sol[0] = 1;
    int z=1;
    visited[0] = true;
    int Prev = 0;

    while(count(visited, visited + n, false) > 0){
        int* minElement = min_element(c[Prev], c[Prev] + n);
        int j = minElement - c[Prev];
        if (visited[j] == false) {
            // cout << (j+1) << " ";
            sol[z]=j+1;
            z++;
            visited[j] = true;
            Prev = j;
        } else {
            c[Prev][j] = INT_MAX;
        }
    }

    for(int i=0; i<n; i++){
        best[i] = sol[i];
    }
    cout << compute(sol) << endl;

    int cnt = 1;
    while(true){
        int p1 = rand() % n;
        int p2 = rand() % n;
        int p3 = rand() % n;
        int p4 = rand() % n;

        while (p1 == p2 || p1 == 0 || p2 == 0) {
            p2 = rand() % n;
            p1 = rand() % n;
        }
        int tmp = sol[p1];
        sol[p1] = sol[p2];
        sol[p2] = tmp;
        cout << compute(sol) << endl;
        if(compute(sol) < compute(best)){
            for(int i=0; i<n; i++){
                best[i] = sol[i];
            }
            cout << compute(best) << endl; 
        }
        cnt++;
        if(cnt == 200000) break;
    }
    for(int i=0; i<n; i++){
        cout << best[i] << " ";
    } 

}
