class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        while(i < j) {
            int m = (i+j)/2;
            if(m>0) {
                if(nums[m] < nums[m-1])
                    return nums[m];
            }
            if(nums[m] > nums[m+1])
                return nums[m+1];
            if(nums[m] > nums[j])
                i=m;
            else
                j=m;
        }
        return nums[i];
    }
};