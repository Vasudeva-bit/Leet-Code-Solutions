class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int maax = -1e9;
        int miin = 1e9;
        
        for(int i=0;i<nums.size();i++){
            if(maax > nums[i])
                count1++;
            maax = max(maax, nums[i]);
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            if(miin < nums[i])
                count2++;
            miin = min(miin, nums[i]);
        }
        
        return count1 <= 1 || count2 <= 1;
        
    }
};