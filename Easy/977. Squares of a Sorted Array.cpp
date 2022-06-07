class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int tem;
            if(abs(nums[l]) < abs(nums[r])){
                tem = nums[r];
                r--;
            }
            else{
                tem = nums[l];
                l++;
            }
            tem *= tem;
            result.push_back(tem);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};