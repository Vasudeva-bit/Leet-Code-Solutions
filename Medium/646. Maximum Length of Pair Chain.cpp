#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> dp;
    int connect(vector<vector<int>>& pairs, int sofar, int i) {
        while(i < pairs.size() and sofar >= pairs[i][0]) {
            i++;
        }
        if(i == pairs.size()) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(1+connect(pairs, pairs[i][1], i+1), connect(pairs, sofar, i+1));
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs), end(pairs));
        dp = vector<int>(pairs.size(), -1);
        return connect(pairs, -1001, 0);
    }
};