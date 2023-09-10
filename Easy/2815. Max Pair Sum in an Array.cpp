#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxDigit(int n)  {
        int largest = 0;

        while (n) {
            int r = n % 10;
            largest = max(r, largest);
            n = n / 10;
        }
        return largest;
    }
    int maxSum(vector<int>& nums) {
        vector<vector<int>> vectr(10);
        for(auto num: nums) {
            vectr[maxDigit(num)].push_back(num);
        }
        for(int i=0;i<10;i++) {
            sort(vectr[i].begin(), vectr[i].end(), greater<int>());
        }
        int out = 0;
        for(int i=0;i<10;i++) {
            int cur = 0;
            if(vectr[i].size() > 1) {
                cur += vectr[i][0]+vectr[i][1];
            }
            out = max(out, cur);
        }
        if(out == 0) return -1;
        else return out;
    }
};