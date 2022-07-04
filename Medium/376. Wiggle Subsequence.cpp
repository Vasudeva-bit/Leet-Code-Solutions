class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> diff;
        for(int i=1;i<nums.size();i++) {
            int dif = nums[i] - nums[i-1];
            if(dif != 0) {
                diff.push_back(dif);
            }
        }
        if(diff.empty())
            return 1;
        int count = 2;
        for(int i=1;i<diff.size();i++) {
            if(diff[i] > 0 && diff[i-1] < 0 ||
               diff[i] < 0 && diff[i-1] > 0)
                count++;
        }
        return count;
    }
};