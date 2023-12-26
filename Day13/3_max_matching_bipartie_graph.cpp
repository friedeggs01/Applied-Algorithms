#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> tasks;
vector<vector<int>> app;

bool bpm(int v, bool seen[], int matchR[]){
    seen[v] = true;
    for (int i=0; i<app[v].size(); i++) { 
        int u = app[v][i];
        if(tasks[u][v] && matchR[v] < 0 || bpm(matchR[v], seen, matchR)) { // if applicant u is interested in job v and job v is not assigned
            matchR[v]=u;
            return true;
        }
    }
    return false;
}

int maxBPM(){
    int matchR[n]; // matchR[i] is the applicant number assigned to job i
    memset(matchR, -1, sizeof(matchR)); // firstly, all jobs are available
    int res = 0;
    for(int v=0; v<n; v++) {
        bool seen[n];
        memset(seen, 0, sizeof(seen));
        if(bpm(v, seen, matchR)){// find if the applicant u can get a job
            res++;
        }
    }
    return res;
}

int main() {
    freopen("3.txt", "r", stdin);
    cin >> n >> m;
    cout << n << m;
    tasks.resize(m, vector<int>(n, 0));
    app.resize(n, vector<int>(m, 0));
    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        for(int j = 0; j <k; j++){
            int tmp;
            cin >> tmp;
            tasks[tmp-1][i] = 1;
            app[i].push_back(tmp);
        }
    }
    cout << maxBPM();
    return 0;
}