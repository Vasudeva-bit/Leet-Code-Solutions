// Method 1: Dynamic Programming with Tabulation
class Solution {
public:
    int n;
    vector<int> dp;
    int jump(vector<int>& nums) {
        n = nums.size();
        dp = vector<int>(n, 0);
        dp[n-1] = 1;
        return DFS(0, nums)-1;
    }
    int DFS(int idx, vector<int>& nums) {
        if(dp[idx] != 0)
            return dp[idx];
        int out = INT_MAX;
        for(int i=1;i<=nums[idx] and (idx+i) < n;i++) {
            out = min(out, DFS(idx+i, nums));
        }
        if(out == INT_MAX)
            return INT_MAX;
        return dp[idx] = out+1;
    }
};
// Method 2: Bottom Top Dynamic Programming Solution
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxi=0;
        int so_far=0;
        int c=0;
        for(int i=0;i<nums.size()-1;i++) {
            maxi = max(maxi, i+nums[i]);
            if(i == so_far) {
                c++;
                so_far = maxi;
                }
            }
        return c;
    }
};