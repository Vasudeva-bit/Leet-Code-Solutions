#include <bits/stdc++.h>
using namespace std;
// tags: Math, DP, Suffix
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int sum = 0;
        int i;
        for(i=n-1;i>=0;i--) {
            sum += satisfaction[i];
            if(sum <= 0)
                break;
        }
        i++;
        int out = 0;
        for(int t=i;t<n;t++) {
            out += (t-i+1)*satisfaction[t];
        }
        return out;
    }
};