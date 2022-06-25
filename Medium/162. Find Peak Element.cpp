class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            int mid = (r-l)/2 + l;
            if(nums[mid] > nums[mid+1]){
                r = mid;
                
            }
            else{
                l = mid + 1;
            }
        }
        return r;
    }
};