#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 10005;
vector<int> graph[MAXN];
int matchR[MAXN];
bool visited[MAXN];
 
bool dfs(int task) {
    visited[task] = true;
    for (int i = 0; i < graph[task].size(); i++) {
        int staff = graph[task][i];
        if (matchR[staff] == -1 || (!visited[matchR[staff]] && dfs(matchR[staff]))) {
            matchR[staff] = task;
            return true;
        }
    }
    return false;
}
 
int maxMatching(int n, int m, const vector<vector<int>>& tasks) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < tasks[i].size(); j++) {
            int staff = tasks[i][j];
            graph[i].push_back(staff);
        }
    }
 
    memset(matchR, -1, sizeof(matchR));
    int maxTasksAssigned = 0;
 
    for (int task = 0; task < n; task++) {
        memset(visited, false, sizeof(visited));
        if (dfs(task)) {
            maxTasksAssigned++;
        }
    }
 
    return maxTasksAssigned;
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> tasks(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        tasks[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> tasks[i][j];
        }
    }
 
    int maxTasksAssigned = maxMatching(n, m, tasks);
    cout << maxTasksAssigned << endl;
 
    return 0;
}