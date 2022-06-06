class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() -1;
        int mid;
        while(l <= r){
            mid  = (r-l)/2 + l;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                r = mid - 1;
            else if(nums[mid] < target)
                l = mid + 1;
        }
        return -1;
    }
};