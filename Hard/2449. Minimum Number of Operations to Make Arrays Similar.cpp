class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        vector<int> oddN, oddT, evenN, evenT;
        int n = target.size();
        for(int i=0;i<n;i++) {
            if(nums[i]%2 == 0)
                evenN.push_back(nums[i]);
            else
                oddN.push_back(nums[i]);
            if(target[i]%2 == 0)
                evenT.push_back(target[i]);
            else
                oddT.push_back(target[i]);
        }
        long long diff = 0;
        n = evenN.size();
        for(int i=0;i<n;i++) {
            diff += abs(1ll*evenN[i] - 1ll*evenT[i])/2;
        }
        n = oddN.size();
        for(int i=0;i<n;i++) {
            diff += abs(1ll*oddN[i] - 1ll*oddT[i])/2;
        }
        return diff/2;
    }
};