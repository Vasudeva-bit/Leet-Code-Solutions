class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int mid;
        while(l<=r){
            mid = (r-l)/2 + l;
            if(nums[mid] == target)
                break;
            else if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid -1;
        }
        l = mid;
        r = mid;
        if(mid < nums.size() && mid>=0 && nums[mid] == target){
            while(l >= 0 && nums[l] == target)
                l--;
            while(r < nums.size() && nums[r] == target)
                r++;
            return {l+1, r-1};
        }
        return {-1, -1};
    }
};