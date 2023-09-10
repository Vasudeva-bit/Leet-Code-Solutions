#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int cnt = 0;
        unordered_map<int, int> umap;
        umap[0] = 1;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            cnt += umap[sum-k];
            umap[sum]++;
        }
        return cnt;
    }
};