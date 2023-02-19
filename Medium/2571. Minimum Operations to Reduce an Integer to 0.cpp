#include <bits/stdc++.h>;
using namespace std;
class Solution {
public:
    int minOperations(int n) {
        vector<int> dp(n+1, 0);
        for(int i=1;i<=n;i++) {
            int uplimit = (int)pow(2, (int)log2(i)+1);
            int lolimit = (int)pow(2, (int)log2(i));
            dp[i] = min(1+dp[uplimit-i], 1+dp[i-lolimit]);
        }
        return dp[n];
    }
};