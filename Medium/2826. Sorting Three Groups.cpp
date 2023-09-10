#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minOps(int i, int j, vector<int>& nums) {
        int count = 0;
        for(int x=0;x<i;x++) {
            if(nums[x] != 1) count++;
        }
        for(int x=i;x<j;x++) {
            if(nums[x] != 2) count++;
        }
        for(int x=j;x<nums.size();x++) {
            if(nums[x] != 3) count++;
        }
        return count;
    }
    int minimumOperations(vector<int>& nums) {
        int out = INT_MAX;
        int n = nums.size();
        for(int i=0;i<=n;i++) {
            for(int j=i;j<=n;j++) {
                out = min(out, minOps(i, j, nums));
            }
        }
        return out;
    }
};