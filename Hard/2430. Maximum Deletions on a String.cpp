int lcp[4001][4001];
class Solution {
public:
    int deleteString(string s) {
        int n=s.length();
        vector<int> dp(n+1,0);
        for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) lcp[i][j]=0;
        for(int i=n-1;i>=0;i--) for(int j=n-1;j>=i;j--) if(s[i]==s[j]) lcp[i][j]=1+lcp[i+1][j+1];
        for(int i=n-1;i>=0;i--) {
            for(int j=i;j<n;j++) {
                if(lcp[i][j] >= j-i) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[0];
    }
};