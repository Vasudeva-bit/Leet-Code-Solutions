class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k != 0)
            return false;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        for(auto n:nums){
            freq[n]++;
        }
        unordered_map<int, int> need;
        for(auto n:nums){
            int c = 0;
            if(freq[n] <= 0)
                continue;
            while(c < k) {
                freq[n+c]--;
                if(freq[n+c] < 0)
                    return false;
                c++;
            }
        }
        return true;
    }
};