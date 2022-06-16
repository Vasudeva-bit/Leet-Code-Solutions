class Solution {
public:
    bool check(vector<int>& nums) {
        int c = 0;
        int i;
        for(i=0;i<nums.size()-1;i++){
            if(nums[i] > nums[i+1])
                c++;
        }
        if(nums[i] > nums[0])
            c++;
        return c<=1;
    }
};