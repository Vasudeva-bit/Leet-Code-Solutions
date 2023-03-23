#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> st;
        st.insert(nums[0]);
        int moves = 0;
        for(int i=1;i<nums.size();i++) {
            if(st.count(nums[i]) == 1) {
                moves += nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1]+1;
            }
            st.insert(nums[i]);
        }
        return moves;
    }
};