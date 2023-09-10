#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        for(auto &n: nums) {
            n = ((n%modulo)==k)?1:0;
        }
        long long cnt = 0;
        long long prefix = 0;
        unordered_map<long long, long long> mp;
        mp[0]++;
        for(int i=0;i<nums.size();i++) {
            prefix += nums[i];
            long long target = (prefix-k+modulo)%modulo;
            cnt += mp[target];
            mp[prefix%modulo]++;
        }
        return cnt;
    }
};