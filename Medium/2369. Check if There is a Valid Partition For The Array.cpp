class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size() + 1);
        dp[0] = 1;
        for(int i=0;i<nums.size();i++) {
            if(dp[i]) {
                if(i+2 <= nums.size()) {
                    if(nums[i] == nums[i+1]) dp[i+2] = 1;
                }
                if(i+3 <= nums.size()) {
                    if(nums[i] == nums[i+1] and nums[i+1] == nums[i+2]) dp[i+3] = 1;
                    if(nums[i]+1 == nums[i+1] and nums[i]+2 == nums[i+2]) dp[i+3] = 1;                   
                }
            }
        }
        return dp.back();
    }
};