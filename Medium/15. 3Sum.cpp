class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
                int j = i+1;
                int k = nums.size()-1;
                while(j<nums.size() && j<k){
                    if(nums[j] + nums[k] == -(nums[i])){
                        while(j != nums.size()-1 && nums[j] == nums[j+1])j++;
                        while(k != 0 && nums[k] == nums[k-1])k--;
                        result.push_back({nums[i], nums[j], nums[k]});
                        j++;
                        k--;
                    }
                    else if(nums[j] + nums[k] > -(nums[i])){
                        while(k != 0 && nums[k] == nums[k-1])k--;
                        k--;
                    }
                    else{
                        while(j != nums.size()-1 && nums[j] == nums[j+1])j++;
                        j++;
                    }
                }
                while(i != nums.size()-1 && nums[i] == nums[i+1])i++;
            }
        return result;
    }
};
