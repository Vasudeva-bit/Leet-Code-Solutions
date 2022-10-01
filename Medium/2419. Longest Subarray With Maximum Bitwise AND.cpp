class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int output = 1;
        int result = 0;
        int maax = *max_element(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;i++) {
            if(maax == nums[i] and nums[i] == nums[i+1])
                output++;
            else {
                result = max(result, output);
                output = 1;
            }
        }
        return max(output,result);
    }
};