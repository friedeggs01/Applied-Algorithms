#include<bits/stdc++.h>
using namespace std;

int maze[1000][1000];
int len;

int bfs(int n, int m, int r, int c){
    queue<int> toado_x;
    queue<int> toado_y;
    toado_x.push(r-1);
    toado_y.push(c-1);
    int action[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int size = 1;
    int move = 0;

    // ensure we cannot visit at where we begin
    maze[r][c] = 1;

    while(!toado_x.empty()) {
        move++;
        int step = toado_x.size();
        for(int i = 0; i < step; i++) {
            // save value of previous position
            int old_x = toado_x.front(); toado_x.pop();
            int old_y = toado_y.front(); toado_y.pop();

            // try 4 action
            for(int j = 0; j < 4; j++) {
                int new_x = old_x + action[j][0];
                int new_y = old_y + action[j][1];
                // check if we can access this position and meet end condition
                if(maze[new_x][new_y] == 0) {
                    if(new_x < 1 || new_x > n-2 || new_y < 1 || new_y > m-2) {
                        return ++move;
                    }
                    // if not reach end condition, push positions in queue to find path
                    toado_x.push(new_x);
                    toado_y.push(new_y);
                    maze[new_x][new_y] = 1;
                }

            }
        }
    }
    return -1;
}

int main() {
    freopen("2.txt","r", stdin);
    // ios_base::sync_with_stdio(false); // cannot use those statements when used scanf
    // cin.tie(NULL);
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> maze[i][j];
        }
    }
    cout << bfs(n, m, r, c) << endl;
    return 0;
}