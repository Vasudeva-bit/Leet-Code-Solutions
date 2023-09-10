#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int maxfreq = 0;
        int left = 0;
        int right = 0;
        unordered_map<int, int> umap;
        for(;right<nums.size();right++) {
            umap[nums[right]]++;
            maxfreq = max(maxfreq, umap[nums[right]]);
            if(right-left+1-maxfreq > k) {
                umap[nums[left]]--;
                left++;
            }
        }
        return maxfreq;
    }
};