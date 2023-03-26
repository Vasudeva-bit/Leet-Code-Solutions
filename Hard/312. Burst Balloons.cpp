#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int DFS(int l, int r, vector<int>& nums) {
        if(l > r) 
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        dp[l][r] = 0;
        for(int i=l;i<=r;i++) {
            int coins = nums[l-1]*nums[i]*nums[r+1];
            coins += DFS(l, i-1, nums) + DFS(i+1, r, nums);
            dp[l][r] = max(dp[l][r], coins);
        }
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        dp = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        return DFS(1, n-2, nums);
    }
};