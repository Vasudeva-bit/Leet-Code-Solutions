class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0] + nums[1] + nums[nums.size()-1];
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++) {
            int a = i+1;
            int b = nums.size()-1;
            while(a < b) {
                int curr = nums[i] + nums[a] + nums[b];
                if(curr > target) 
                    b--;
                else
                    a++;
                result = (abs(curr-target) < abs(result-target))?curr:result;
            }
        }
        return result;
    }
};