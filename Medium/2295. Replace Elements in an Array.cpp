class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        for(int i=0;i<operations.size();i++){
            int idx = mp[operations[i][0]];
            mp.erase(operations[i][0]);
            mp[operations[i][1]] = idx;
        }
        for(auto i:mp){
            nums[i.second] = i.first;
        }
        return nums;
    }
};