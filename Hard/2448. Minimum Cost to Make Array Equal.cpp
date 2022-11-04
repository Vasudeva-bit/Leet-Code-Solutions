class Solution {
public:
    long long compute(vector<int>& nums, vector<int>& cost, long long median) {
        long long out = 0;
        for(int i=0;i<nums.size();i++) {
            out += abs(median - (1ll*nums[i]))*(1ll*cost[i]);
        }
        return out;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int, int>> pair;
        long long n = nums.size();
        long long sum = 0;
        for(int i=0;i<n;i++) {
            pair.push_back({nums[i], cost[i]});
            sum += 1ll*cost[i];
        }
        sort(pair.begin(), pair.end());
        long long tot = 0;
        int i = 0;
        long long median;
        while(tot < (sum+1)/2 and i < n) {
            tot += 1ll*pair[i].second;
            median = pair[i].first;
            i++;
        }
        return compute(nums, cost, median);
    }
};