class Solution {
public:
    int countVowelPermutation(int n) {
        vector<int> dp = {1, 1, 1, 1, 1};
        int a = 0;
        int e = 1;
        int i = 2;
        int o = 3;
        int u = 4;
        vector<int> tem(5, 0);
        int mod = 1e9 + 7;
        for(int j=1;j<n;j++) {
            tem[a] = ((dp[e] + dp[i])% mod + dp[u]) % mod;
            tem[e] = (dp[a] + dp[i]) % mod;
            tem[i] = (dp[o] + dp[e]) % mod;
            tem[o] = (dp[i]);
            tem[u] = (dp[i] + dp[o]) % mod;
            dp = tem;
            tem = {0, 0, 0, 0, 0};
        }
        int sum = 0;
        for(int i=0;i<5;i++) {
            sum = (sum + dp[i]) % mod;
        }
        return sum;
    }
};