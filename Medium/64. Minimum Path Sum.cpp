#include <bits/stdc++.h>
using namespace std;
// tags: DP, C++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m, n;
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int r=0;r<m;r++) {
            for(int c=0;c<n;c++) {
                if(c == 0)
                    dp[r+1][c+1] = dp[r][c+1];
                else if(r == 0)
                    dp[r+1][c+1] = dp[r+1][c];
                else
                    dp[r+1][c+1] = min(dp[r][c+1], dp[r+1][c]);
                dp[r+1][c+1] += grid[r][c];
            }
        }
        return dp[m][n];
    }
};