#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible_pairs(int diff, vector<int>& nums, int p) {
        int i = 0;
        int count = 0;
        while(i+1 < nums.size() and count < p) {
            if(abs(nums[i] - nums[i+1]) <= diff) {
                count++;
                i++;
            }
            i++;
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = abs(nums[0]-nums[n-1]);
        int low = 0;
        int high = diff;
        while(low < high) {
            int mid = low + (high-low)/2;
            if(possible_pairs(mid, nums, p))
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};