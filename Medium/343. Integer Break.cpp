#include <bits/stdc++.h>
using namespace std;
// tags: Dynamic Programming, Recursion, Memoization
class Solution {
public:
    vector<int> memo;
    int recur(int n) {
        if(memo[n] != -1)
            return memo[n];
        memo[n] = INT_MIN;
        for(int i=1;i<n;i++) {
            memo[n] = max(i*recur(n-i), memo[n]);
        }
        return memo[n];
    }
    int integerBreak(int n) {
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        memo = vector<int>(n+2, -1);
        memo[0] = 0;
        memo[1] = 1;
        return recur(n+1);
    }
};