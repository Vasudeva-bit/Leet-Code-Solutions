#include <bits/stdc++.h>
using namespace std;
// Method 1: Easy Implementation
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int mid;
        int r = nums.size() - 1;
        while(l<r){
            mid = (l+r)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                l = mid+1;
            else if(nums[mid] > target)
                r = mid-1;
        }
        if(target > nums[(l+r)/2])
            return (l+r)/2+1;
        else
            return (l+r)/2;
    }
};
// Method 2: Efficient Implementation
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        int mid;
        while(i <= j) {
            mid = (i+j)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target) 
                i = mid+1;
            else
                j = mid-1;
        }
        if(target > nums[mid])
            return mid+1;
        else
            return mid;
    }
};