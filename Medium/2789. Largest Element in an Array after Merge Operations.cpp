#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long out = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--) {
            if(out >= nums[i])
                out += nums[i];
            else 
                out = nums[i];
        }
        return out;
    }
};