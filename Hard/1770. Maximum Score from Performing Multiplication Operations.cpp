class Solution {
public:
    vector<vector<int>> dp;
    int maximumScore(vector<int>& n, vector<int>& m) {
        dp.resize(m.size() + 1, vector<int>(m.size() + 1, INT_MIN));
        return helper(0, n.size()-1, 0, m, n);      
    }
    int helper(int i, int j, int x, vector<int>& m, vector<int>& n) {
        if(x == m.size()) {
            return 0;
        }
        if(dp[x][i] != INT_MIN)
            return dp[x][i];
        int l = m[x]*n[i] + helper(i+1, j, x+1, m, n);
        int r = m[x]*n[j] + helper(i, j-1, x+1, m ,n);
        return dp[x][i] = max(l, r);
    }
};