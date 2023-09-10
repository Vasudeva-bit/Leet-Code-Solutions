#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int cnt = 0;
        int i=0, j=0;
        while(j < nums.size()) {
            umap[nums[j]]++;
            while(umap.size() > k) {
                umap[nums[i]]--;
                if(umap[nums[i]] == 0) umap.erase(nums[i]);
                i++;
            }
            cnt += j-i+1;
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};