#include <bits/stdc++.h>
using namespace std;
// tags: Dynamic Programming, Recursion, Memoization
class Solution {
public:
    vector<int> dp;
    int recur(int n, vector<int>& days, vector<int>& costs) {
        if(dp[n] != INT_MAX)
            return dp[n];
        int seven = lower_bound(days.begin(), days.end(), days[n]+7)-days.begin();
        int thirty = lower_bound(days.begin(), days.end(), days[n]+30)-days.begin();
        if(n+1 <= days.size())
            dp[n] = min(dp[n], costs[0]+recur(n+1, days, costs));
        if(seven <= days.size())
            dp[n] = min(dp[n], costs[1]+recur(seven, days, costs));
        if(thirty <= days.size())
            dp[n] = min(dp[n], costs[2]+recur(thirty, days, costs));
        return dp[n];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        dp = vector<int>(n+1, INT_MAX);
        dp[n] = 0;
        return recur(0, days, costs);
    }
};