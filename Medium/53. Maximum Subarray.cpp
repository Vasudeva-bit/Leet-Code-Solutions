#include <bits/stdc++.h>
using namespace std;
// tags: Two Pointers, Vector, C++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int out = nums[0];
        int sum = nums[0];
        int i=0;
        int j=1;
        int n = nums.size();
        for(;j<n;j++) {
            sum += nums[j];
            while(i < j and sum < nums[j]) {
                sum -= nums[i];
                i++;
            }
            out = max(out, sum);
        }
        return out;
    }
};