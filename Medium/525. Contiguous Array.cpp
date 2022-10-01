class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_len = 0;
        int cum_sum = 0;
        unordered_map<int, int> lookup;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 0)
                cum_sum -= 1;
            else
                cum_sum += 1;
            if(cum_sum == 0)
                max_len = i+1;
            else if(lookup.find(cum_sum) != lookup.end())
                max_len = max(max_len, i - lookup[cum_sum]);
            else
                lookup[cum_sum] = i;
        }
        return max_len;
    }
};