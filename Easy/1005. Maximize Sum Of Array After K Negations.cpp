class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        while(k > 0) {
            sort(nums.begin(), nums.end());
            if(nums[0] == 0)
                break;
            else {
                nums[0] = -1*nums[0];
                k--;
            }
        }
        int sum = 0;
        for(auto it: nums) {
            sum += it;
        }
        return sum;
    }
};