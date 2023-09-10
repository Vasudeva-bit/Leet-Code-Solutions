#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int dp[11][2][11][11][21];
    int solve(int id, bool tight, int even, int odd, int rem, bool zeros, int k, string s) {
        if(id == s.size())
            return even == odd and rem == 0;
        if(dp[id][tight][even][odd][rem] != -1) return dp[id][tight][even][odd][rem];
        int up = tight?s[id]-'0':9;
        int out = 0;
        for(int i=0;i<=up;i++) {
            bool ntight = tight and i == up;
            bool nzeros = zeros and i == 0;
            int nrem = (rem*10+i)%k;
            if(i%2 == 0) {
                out += solve(id+1, ntight, nzeros?even:even+1, odd, nrem, nzeros, k, s);
            }
            else {
                out += solve(id+1, ntight, even, odd+1, nrem, nzeros, k, s);
            }
        }
        dp[id][tight][even][odd][rem] = out;
        return out;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        memset(dp, -1, sizeof(dp));
        string l = to_string(low-1);
        int lc = solve(0, 1, 0, 0, 0, 1, k, l);
        memset(dp, -1, sizeof(dp));
        string h = to_string(high);
        int hc = solve(0, 1, 0, 0, 0, 1, k, h);
        return hc-lc;
    }
};