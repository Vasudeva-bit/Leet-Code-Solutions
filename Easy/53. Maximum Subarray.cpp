class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxx = nums[0];
        int curr = nums[0];
        for(int i=1;i<nums.size();i++){
            curr = max(nums[i], nums[i]+curr);
            maxx = max(maxx, curr);
        }
        return maxx;
    }
};