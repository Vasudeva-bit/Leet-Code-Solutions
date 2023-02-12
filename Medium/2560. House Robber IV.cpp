class Solution {
public:
    bool check(vector<int>& nums, int mid, int k) {
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] <= mid) {
                i += 2;
                k--;
            }
            else
                i++;
            if(k == 0)
                return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int out = INT_MAX;
        int l = 1;
        int r = 1e9;
        while(l <= r) {
            int mid = l+(r-l)/2;
            if(check(nums, mid, k)) {
                out = min(out, mid);
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return out;
    }
};