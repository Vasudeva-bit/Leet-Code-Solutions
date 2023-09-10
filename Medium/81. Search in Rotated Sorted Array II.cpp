#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] == target)
                return true;
            if(nums[mid] == nums[low] and nums[mid] == nums[high]) {
                low++;
                high--;
            }
            else if(nums[mid] >= nums[low]) {
                if(nums[low] > target or nums[mid] < target)
                    low = mid+1;
                else 
                    high = mid-1;
            }
            else {
                if(nums[high] < target or nums[mid] > target)
                    high = mid-1;
                else
                    low = mid+1;
            }
        }
        return false;
    }
};