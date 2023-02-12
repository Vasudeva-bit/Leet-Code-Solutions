class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long out = 0;
        for(int i=0;i<n;i++) {
            int tlower = lower-nums[i];
            int tupper = upper-nums[i];
            out += upper_bound(nums.begin()+(i+1), nums.end(), tupper) - lower_bound(nums.begin()+(i+1), nums.end(), tlower);
        }
        return out;
    }
};