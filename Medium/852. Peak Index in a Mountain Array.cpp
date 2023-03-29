#include <bits/stdc++.h>
using namespace std;
// tags: C++, Binary Search, Array
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size()-1;
        int mid;
        while(l < r) {
            mid = l+(r-l)/2;
            if(arr[mid] < arr[mid+1])
                l = mid;
            else if(arr[mid] < arr[mid-1])
                r = mid;
            else 
                return mid;
        }
        return mid;
    }
};