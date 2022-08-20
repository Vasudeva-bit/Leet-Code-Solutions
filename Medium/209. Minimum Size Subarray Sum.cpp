class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;
        int up = 0;
        for(int i=0;i<nums.size();i++) {
            target -= nums[i];
            while(target <= 0) {
                result = min(result, i-up+1);
                target += nums[up++];
            }
        }
        if(result != INT_MAX) 
            return result;
        return 0;
    }
};