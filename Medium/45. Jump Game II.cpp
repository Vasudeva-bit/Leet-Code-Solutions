class Solution {
public:
    int jump(vector<int>& nums) {
        int maxi=0;
        int so_far=0;
        int c=0;
        for(int i=0;i<nums.size()-1;i++) {
            maxi = max(maxi, i+nums[i]);
            if(i == so_far) {
                c++;
                so_far = maxi;
                }
            }
        return c;
    }
};