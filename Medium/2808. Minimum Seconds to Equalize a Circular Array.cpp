#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, int> lastSeen, maxDis;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(lastSeen.find(nums[i]) != lastSeen.end()) {
                maxDis[nums[i]] = max(maxDis[nums[i]], i - lastSeen[nums[i]]-1);
            }
            lastSeen[nums[i]] = i;
        }
        for(int i = 0; i < n; ++i) {
            maxDis[nums[i]] = max(maxDis[nums[i]], (i - lastSeen[nums[i]] -1 + n )%n );
            lastSeen[nums[i]] = i;
        }
        int out = INT_MAX;
        for(auto ele: maxDis) {
            out = min(out, ele.second);
        }
        return (out+1)/2;
    }
};