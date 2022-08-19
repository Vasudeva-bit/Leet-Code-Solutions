class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        for(auto i:nums) {
            g = gcd(g, i);
        }
        return (g == 1);
    }
};