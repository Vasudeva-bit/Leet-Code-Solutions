#include <bits/stdc++.h>
using namespace std;
// tags: C++, Binary Search, Array
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);
        int tot = nums1.size() + nums2.size();
        int half = tot/2;
        int l = 0;
        int r = nums1.size();
        while(l <= r) {
            int i = (l+r)/2;
            int j = half-i;
            double left1 = (i == 0)?INT_MIN:nums1[i-1];
            double left2 = (j== 0)?INT_MIN:nums2[j-1];
            double right1 = (i == nums1.size())?INT_MAX:nums1[i];
            double right2 = (j == nums2.size())?INT_MAX:nums2[j];
            if(left1 <= right2 and left2 <= right1) {
                if(tot%2) {
                    return min(right1, right2);
                }
                return (max(left2, left1)+min(right1, right2))/2;
            }
            else if(left1 > right2) 
                r = i-1;
            else
                l = i+1;
        }
        return 0.0;
    }
};