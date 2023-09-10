#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> umap1, umap2;
        for(auto num: nums) {
            umap1[num]++;
        }
        int len = umap1.size();
        int count = 0;
        int j = 0;
        for(int i=0;i<nums.size();i++) {
            umap2[nums[i]]++;
            while(j <= i and umap2.size() == len) {
                umap2[nums[j]]--;
                if(umap2[nums[j]] == 0)
                    umap2.erase(nums[j]);
                count += nums.size()-i;
                j++;
            }
        }
        return count;
    }
};