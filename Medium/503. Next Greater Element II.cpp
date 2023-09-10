#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> out;
        stack<int> st;
        int n = nums.size();
        for(int i=n*2-1;i>=0;i--) {
            while(!st.empty() and nums[i%n] >= st.top()) st.pop();
            if(i < n) {
                if(st.empty()) out.push_back(-1);
                else out.push_back(st.top());
            }
            st.push(nums[i%n]);
        }
        reverse(begin(out), end(out));
        return out;
    }
};