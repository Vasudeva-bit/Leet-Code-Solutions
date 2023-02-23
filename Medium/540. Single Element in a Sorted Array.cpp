#include <bits/stdc++.h>
using namespace std;
// Method 1: Intuitive & O(n)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int exor = 0;
        for(int val: nums) {
            exor ^= val;
        }
        return exor;
    }
};
// Method 2: Efficient & O(log n)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int exor = 0;
        int i=0;
        int j=nums.size()-1;
        while(i < j) {
            exor ^= nums[i++];
            exor ^= nums[j--];
        }
        return exor^nums[i];
    }
};