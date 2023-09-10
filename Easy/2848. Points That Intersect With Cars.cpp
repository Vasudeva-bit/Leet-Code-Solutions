#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        
        int out = 0;
        for(int i=0;i<n;i++) {
            int start = nums[i][0];
            while(i < n-1 and nums[i][1] >= nums[i+1][0]) {
                nums[i+1][1] = max(nums[i][1], nums[i+1][1]);
                i++;
            }
            out += nums[i][1]-start+1;
        }
        return out;
    }
};