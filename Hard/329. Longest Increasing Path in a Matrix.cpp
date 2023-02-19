#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    int r, c;
    int DFS(int i, int j, vector<vector<int>>& matrix, int prev) {
        if(i < 0 or j < 0 or i >= r or j >= c or prev >= matrix[i][j])
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int di[] = {0, 0, -1, 1};
        int dj[] = {1, -1, 0, 0};
        dp[i][j] = 1;
        for(int t=0;t<4;t++) {
            int ni = i+di[t];
            int nj = j+dj[t];
            dp[i][j] = max(dp[i][j], 1+DFS(ni, nj, matrix, matrix[i][j]));
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        r = matrix.size();
        c = matrix[0].size();
        dp = vector<vector<int>>(r, vector<int>(c, -1));
        int out = 1;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                out = max(out, DFS(i, j, matrix, -1));
            }
        }
        return out;
    }
};