#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    unordered_map<int, int> dp;
    int offer(int i, vector<vector<int>>& offers) {
        if(i >= offers.size())
            return 0;
        if(dp.find(i) != dp.end()) return dp[i];
        int out = offer(i+1, offers);
        int next = offers[i][1]+1;
        int low = i+1;
        int high = offers.size()-1;
        while(low <= high) {
            int mid = (low+high)/2;
            if(offers[mid][0] >= next)
                high = mid-1;
            else
                low = mid+1;
        }
        out = max(out, offers[i][2]+offer(low, offers));
        return dp[i] = out;
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        return offer(0, offers);
    }
};