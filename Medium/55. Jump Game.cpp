class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size()-1;
        for(int i=0;i<n;i++){
            maxi = max(maxi, i+nums[i]);
            if(maxi == i)
                break;
        }
        if(maxi >= n)
            return true;
        else
            return false;
    }
};