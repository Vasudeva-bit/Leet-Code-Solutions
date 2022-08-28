class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        while(true) {
            if(find(nums.begin(), nums.end(), original) != nums.end())
                original *= 2;
            else
                return original;
        }
        return original;
    }
};