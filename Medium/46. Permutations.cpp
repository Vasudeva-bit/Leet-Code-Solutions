#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
        if(nums.size() == 1)
            return {nums};
        for(int i=0;i<nums.size();i++) {
            int curr = nums[nums.size()-1];
            nums.pop_back();
            auto perms = permute(nums);
            for(auto &permut: perms) {
                permut.push_back(curr);
                out.push_back(permut);
            }
            nums.insert(nums.begin(), curr);
        }
        return out;
    }
};