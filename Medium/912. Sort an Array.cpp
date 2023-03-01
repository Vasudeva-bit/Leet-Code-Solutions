#include <bits/stdc++.h>
using namespace std;
// Method 1: Time Limit Exceeded (TLE) using Quick Sort (failing if all the elements are equal)
class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int randNum = rand()%(r-l + 1) + l;
        swap(nums[randNum], nums[r]);
        int pivot = nums[r];
        int i = l-1;
        for(int j=l;j<=r;j++) {
            if(nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[r]);
        return i+1;
    }
    void quickSort(vector<int>& nums, int l, int r)  {
        if(l > r) return;
        int q = partition(nums, l, r);
        quickSort(nums, l, q-1);
        quickSort(nums, q+1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};
// Method 2: Merge Sort
class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r) {
        vector<int> vectr;
        int i = l;
        int j = mid+1;
        while(i < mid+1 and j <= r) {
            if(nums[j] <= nums[i])
                vectr.push_back(nums[j++]);
            else 
                vectr.push_back(nums[i++]);
        }
        while(i < mid+1) 
            vectr.push_back(nums[i++]);
        while(j <= r)
            vectr.push_back(nums[j++]);
        i = l;
        for(auto val: vectr) {
            nums[i++] = val;
        }
    }
    void mergeSort(vector<int>& nums, int l, int r) {
        if(l >= r) return;
        int mid = (l+r)/2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid+1, r);
        merge(nums, l, mid, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};
// Method 3: Radix Sort (Non-Comparision Algorithm)

