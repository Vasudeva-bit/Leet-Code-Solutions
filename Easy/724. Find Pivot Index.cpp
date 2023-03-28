#include <bits/stdc++.h>
using namespace std;
// tags: Prefix Sum, Vector, Array
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n+1, 0);
        vector<int> postSum(n+1, 0);
        for(int i=0;i<n;i++) {
            preSum[i+1] = preSum[i]+nums[i];
        }
        for(int i=n-1;i>=0;i--) {
            postSum[i] = postSum[i+1]+nums[i];
        }
        for(int i=0;i<n;i++) {
            if(postSum[i+1] == preSum[i])
                return i;
        }
        return -1;
    }
};