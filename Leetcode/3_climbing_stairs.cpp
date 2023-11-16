#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2) {
            return n;
        }
        vector<int> dp(46, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i=3;i<=n;++i){
            dp[i]=dp[i-1]+dp[i-2]; // if you reach (i-2) just make 2 step, if you reach (i-1) just make 1 step 
        }
        return dp[n];
    }
};