#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> out(n);
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            out[i] = sum;
        }
        sum = 0;
        for(int i=n-1;i>=0;i--) {
            sum += nums[i];
            out[i] = abs(out[i] - sum);
        }
        return out;
    }
};