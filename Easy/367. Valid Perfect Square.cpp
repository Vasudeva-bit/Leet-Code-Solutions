#include <bits/stdc++.h>
using namespace std;
// tags: C++, DP, Array
class Solution {
public:
    bool isPerfectSquare(int num) {
        vector<bool> dp(long(num)+1, false);
        for(long i=1;i*i<=num;i++) {
            dp[i*i] = true; 
        }
        return dp[num];
    }
};