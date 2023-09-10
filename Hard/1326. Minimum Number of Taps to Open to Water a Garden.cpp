#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1, 100000);
        dp[0] = 0;
        for(int i=0;i<=n;i++) {
            int s = max(0, i-ranges[i]);
            int e = min(n, i+ranges[i]);
            for(int j=s+1;j<=e;j++) {
                dp[j] = min(dp[j], dp[s]+1);
            }
        }
        return (dp[n] != 100000)?dp[n]:-1;
    }
};