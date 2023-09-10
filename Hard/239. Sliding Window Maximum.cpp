#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1)
            return nums;
        vector<int> out;
        deque<int> dq;
        for(int i=0;i<n;i++) {
            while(!dq.empty() and dq.front() < i-k+1)
                dq.pop_front();
            while(!dq.empty() and nums[i] > nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            if(i+1>=k) 
                out.push_back(nums[dq.front()]);
        }
        return out;
    }
};