#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int prev = nums.back();
        long long ops = 0;
        for(auto it=nums.rbegin()+1;it!=nums.rend();it++) {
            int num = *it;
            int num_ops = (num+prev-1)/prev;
            ops += num_ops-1;
            prev = num/num_ops;
        }
        return ops;
    }
};