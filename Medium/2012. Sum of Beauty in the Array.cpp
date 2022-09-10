class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int result = 0;
        int maxLeft = 0;
        int minRight = INT_MAX;
        vector<pair<int, int>> tem(nums.size());
        for(int i=1;i<nums.size();i++) {
            if(nums[i-1] > maxLeft)
                maxLeft = nums[i-1];
            tem[i].first = maxLeft;
        }
        for(int i=nums.size()-2;i>=0;i--) {
            if(nums[i+1] < minRight)
                minRight = nums[i+1];
            tem[i].second = minRight;
        }
        for(int i=1;i<nums.size()-1;i++) {
            if(nums[i] > tem[i].first and nums[i] < tem[i].second)
                result += 2;
            else if(nums[i] > nums[i-1] and nums[i] < nums[i+1])
                result += 1;
        }
        return result;
    }
};