class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<string, int> map;
        for(auto i:nums){
            if(map[to_string(i)] > 0)
                return true;
            map[to_string(i)] ++;
        }
        return false;
    }
};