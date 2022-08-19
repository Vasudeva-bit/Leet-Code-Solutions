class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while(n > 0) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        map<int, vector<int>> mp;
        sort(nums.begin(), nums.end(), greater<int>());
        for(auto n:nums) {
            mp[digitSum(n)].push_back(n);
        }
        int result = -1;
        for(auto ele:mp) {
            if(ele.second.size() <= 1) continue;
            result = max(result, (ele.second[0] + ele.second[1]));
        }
        return result;
    }
};