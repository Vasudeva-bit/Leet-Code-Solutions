class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());
        auto it = find(nums.begin(), nums.end(), max);
        nums.erase(it);
        int index = abs(nums.begin()-it);
        int min = *max_element(nums.begin(), nums.end());
        if(max >= 2*min)
            return index;
        else
            return -1;
    }
};