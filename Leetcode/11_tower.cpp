#include<bits/stdc++.h>
using namespace std;

int n, a, b, c;
int cnt = 0;
int dp[31];
struct Block{
    int x, y, z;
    Block(int a=0, int b=0, int c=0){
        x=a, y=b, z=c;
    }
    bool operator < (const Block& a) const{return x*y < a.x * a.y;}

} block[2000];

int max_height(){
    int ans = -1;

    return ans;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    while(true){
        int num_blocks = 0;
        cnt++;
        cin >> n;
        if(n==0) break;
        else {
            for (int i=0; i<n; i++) {
                cin >> a >> b >> c;
                block[num_blocks++] = Block(a,b,c);
                block[num_blocks++] = Block(a,c,b);
                block[num_blocks++] = Block(b,a,c);
                block[num_blocks++] = Block(b,c,a);
                block[num_blocks++] = Block(c,a,b);
                block[num_blocks++] = Block(c,b,a);
            }
            sort(block, block+num_blocks);
            memset(dp, 0, sizeof(dp));
            int max_height = 0;
            for (int j=0; j<num_blocks; j++){
                dp[j] = block[j].z;
                for (int k=0; k<j; k++){
                    if(block[k].x < block[j].x && block[k].y < block[j].y)
                        dp[j] = max(dp[j], dp[k]+block[j].z);
                max_height = max(max_height, dp[j]);
                }
            }
            cout << "Case " << cnt << ": maximum height = " << max_height << endl;
        }
    }
}