#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int dp[1001][1001];
    vector<int> nums1, nums2;
    int MaxSum(int row, int index) {
        if(row == 0 or index < 0) return 0;
        if(dp[row][index] != -1) return dp[row][index];
        dp[row][index] = max(MaxSum(row, index-1), nums1[index]+row*nums2[index]+MaxSum(row-1, index-1));
        return dp[row][index];
    }
    int minimumTime(vector<int>& n1, vector<int>& n2, int x) {
        memset(dp, -1, sizeof(dp));
        int n = n1.size();
        nums1.clear();
        nums2.clear();
        nums1.resize(n);
        nums2.resize(n);
        vector<pair<int, int>> vectr;
        for(int i=0;i<n;i++) {
            vectr.push_back({n2[i], n1[i]});
        }
        sort(vectr.begin(), vectr.end());
        for(int j=0;j<n;j++) {
            nums1[j] = vectr[j].second;
            nums2[j] = vectr[j].first;
        }
        int sum;
        for(int op=0;op<=n;op++) {
            sum = 0;
            for(int j=0;j<n;j++) sum += nums1[j]+(op*nums2[j]);
            if(sum - MaxSum(op, n-1) <= x) return op;
        }
        return -1;
    }
};