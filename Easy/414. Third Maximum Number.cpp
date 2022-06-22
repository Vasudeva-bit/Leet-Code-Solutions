class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int result = *max_element(nums.begin(), nums.end());
        set<int> s(nums.begin(), nums.end());
        vector<int> res(s.begin(), s.end());
        sort(res.begin(), res.end());
        if(res.size()>2){
            res.pop_back();
            res.pop_back();
            result = *max_element(res.begin(), res.end());
        }
        return result;
    }
};