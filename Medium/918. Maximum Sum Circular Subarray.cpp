#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mxsum = 0;
        int mnsum = 0;
        int mxarr = INT_MIN;
        int mnarr = INT_MAX;
        int ttsum = 0;
        for(auto n: nums) {
            mxsum += n; ttsum += n; mnsum += n;
            mxarr = max(mxarr, mxsum);
            if(mxsum < 0) mxsum = 0;
            mnarr = min(mnarr, mnsum);
            if(mnsum > 0) mnsum = 0;
        }
        if(ttsum == mnarr) return mxarr;
        return max(mxarr, ttsum-mnarr);
    }
};