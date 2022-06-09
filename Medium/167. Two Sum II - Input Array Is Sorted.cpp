class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        vector<int> result(2, 0);
        while(i < j){
            if(nums[i] + nums[j] == target){
                result[0] = i+1;
                result[1] = j+1;
                break;
            }
            if(nums[i] + nums[j] > target)
                j--;
            if(nums[i] + nums[j] < target)
                i++;
        }
        return result;
    }
};