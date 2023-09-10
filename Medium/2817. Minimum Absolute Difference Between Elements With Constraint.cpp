#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> s;
        int n = nums.size();
        int out = 1000000000;
        for(int i=0;i<n;i++) {
            if(i >= x)
                s.insert(nums[i-x]);
            auto it = s.lower_bound(nums[i]);
            if(it != s.end()) out = min(out, abs(*it-nums[i]));
            if(it != s.begin()) out = min(out, abs(*(--it)-nums[i]));
        }
        return out;
    }
};