class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> out;
        for(int i=0;i<n;i++) {
            out.push_back(nums[i]);
            out.push_back(nums[i+n]);
        }
        return out;
    }
};