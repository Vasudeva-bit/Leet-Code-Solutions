#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<pair<int, int>, int> umap;
    int recurSolve(vector<int>& nums, int target, int curSum, int pos) {
        if(pos == nums.size()) {
            if(curSum == target) return 1;
            return 0;
        }
        if(umap.find({pos, curSum}) != umap.end())
            return umap[{pos, curSum}];
        umap[{pos, curSum}] = recurSolve(nums, target, curSum+nums[pos], pos+1) +
                              recurSolve(nums, target, curSum-nums[pos], pos+1);
        return umap[{pos, curSum}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return recurSolve(nums, target, 0, 0);
    }
};