#include <bits/stdc++.h>
using namespace std;
// tags: C++, Dynamic Programming, Recursion
class Solution {
public:
    int mod = 1e9+7;
    int n, m;
    vector<vector<int>> preSum;
    vector<vector<vector<int>>> dp;
    int solve(int r, int c, int k) {
        if(!preSum[r][c]) return 0;
        if(!k) return 1;
        if(dp[k][r][c] != -1) return dp[k][r][c];
        int out = 0;
        for(int nr=r+1;nr<n;nr++) {
            if(preSum[r][c] - preSum[nr][c] > 0)
                out = (out+solve(nr, c, k-1))%mod;
        }
        for(int nc=c+1;nc<m;nc++) {
            if(preSum[r][c] - preSum[r][nc] > 0)
                out = (out+solve(r, nc, k-1))%mod;
        }
        return dp[k][r][c] = out;
    }
    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza[0].size();
        dp = vector<vector<vector<int>>>(k, vector<vector<int>>(n, vector<int>(m, -1)));
        preSum = vector<vector<int>>(n+1, vector<int>(m+1, 0));
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                preSum[i][j] = preSum[i+1][j] + preSum[i][j+1] - preSum[i+1][j+1] + bool(pizza[i][j] == 'A');
            }
        }
        return solve(0, 0, k-1);
    }
};
// Please consider upvoting, if the solution helped! Thank you :)
// Credits: DeepCodes (YouTube Channel)