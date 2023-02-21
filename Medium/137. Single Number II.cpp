#include <bits/stdc++.h>
using namespace std;
// Method 0: The sort and find (naive and straight forward implementation)
// Method 1: Most intuitive (two pointers)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cur = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[cur] == nums[i])
                count++;
            if(count == 3) {
                count = 1;
                cur++;
                i=0;
            }
        }
        return nums[cur];
    }
};
// Method 2: Most Efficient (Bit Manip)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for(auto val: nums) {
            ones = (ones^val)&(~twos);
            twos = (twos^val)&(~ones);
        }
        return ones;
    }
};

