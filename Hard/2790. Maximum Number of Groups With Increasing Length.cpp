#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        long long count = 0;
        long long sum = 0;
        for(auto val: usageLimits) {
            sum += val;
            if(sum >= ((count+1)*(count+2))/2) {
                count++;
            }
        }
        return (int)count;
    }
};