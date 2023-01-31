class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        int out = 0;
        vector<pair<int, int>> pairs;
        for(int i=0;i<n;i++) {
            pairs.push_back(make_pair(ages[i], scores[i]));
        }
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 0);
        for(int i=0;i<n;i++) {
            dp[i] = pairs[i].second;
            for(int j=0;j<i;j++) {
                if(pairs[j].second <= pairs[i].second) {
                    dp[i] = max(dp[i], dp[j]+pairs[i].second);
                }
            }
            out = max(dp[i], out);
        }
        return out;
    }
};