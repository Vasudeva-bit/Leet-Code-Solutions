#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size();
        int j = n/2;
        int out = 0;
        while(i < (n/2) and j < n) {
            if(nums[i]*2 <= nums[j]) {
                out += 2;
                i++;
            }
            j++;
        }
        return out;
    }
};