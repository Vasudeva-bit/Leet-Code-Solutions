#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    int dp[2000][2000];
    bool jump(vector<int>& stones, int i, int k) {
        if(i == n-1) return true;
        if(dp[i][k] != -1) return dp[i][k];
        bool flag = false;
        if(k>1 and mp.find(stones[i]+k-1) != mp.end()) {
            flag = flag or jump(stones, mp[stones[i]+k-1], k-1);
        }
        if(mp.find(stones[i]+k) != mp.end()) {
            flag = flag or jump(stones, mp[stones[i]+k], k);
        }
        if(mp.find(stones[i]+k+1) != mp.end()) {
            flag = flag or jump(stones, mp[stones[i]+k+1], k+1);
        }
        return dp[i][k] = flag;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        if(stones[1]-stones[0] != 1) return false;
        
        for(int i=0;i<n;i++) {
            mp[stones[i]] = i;
        }
        memset(dp, -1, sizeof(dp));
        return jump(stones, 1, 1);
    }
};