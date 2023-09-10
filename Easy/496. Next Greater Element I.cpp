#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        int n = nums2.size();
        mp[nums2[n-1]] = -1;
        st.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--) {
            while(!st.empty() and nums2[i] >= st.top()) {
                st.pop();
            }
            if(st.empty()) {
                mp[nums2[i]] = -1;
            }
            else {
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> out;
        for(auto v: nums1) {
            out.push_back(mp[v]);
        }
        return out;
    }
};