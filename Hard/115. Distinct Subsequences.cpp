#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
class Solution {
public:
    vector<vector<ll>> dp;
    int DFS(string s, string t, int i, int j) {
        if(t.size() == j)
            return 1;
        if(s.size() == i)
            return 0;
        if(dp[i][j] != -1) 
            return dp[i][j];
        if(s[i] == t[j]) 
            dp[i][j] = DFS(s, t, i+1, j+1) + DFS(s, t, i+1, j);
        else
            dp[i][j] = DFS(s, t, i+1, j);
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        dp = vector<vector<ll>>(s.size(), vector<ll>(t.size()+1, -1));
        return DFS(s, t, 0, 0);
    }
};