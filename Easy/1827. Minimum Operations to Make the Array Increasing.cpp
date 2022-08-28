class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        int sum = 0;
        for(int i=1;i<nums.size();i++) {
            int res = max(nums[i-1] + 1, nums[i]);
            sum += abs(res - nums[i]);
            nums[i] = res;
        }
        return sum;
    }
};