#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, string& s) {
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int out = INT_MAX;
        for(int k=i;k<j;k++) {
            out = min(out, solve(i, k, s)+solve(k+1, j, s));
        }
        if(s[i] == s[j])
            out--;
        dp[i][j] = out;
        return dp[i][j];
    }
    int strangePrinter(string s) {
        int j = s.size()-1;
        int i = 0;
        dp = vector<vector<int>>(j+1, vector<int>(j+1, -1));
        return solve(i, j, s);
    }
};