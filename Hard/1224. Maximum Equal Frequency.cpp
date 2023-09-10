#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int cnt[100001];
    int freq[100001];
    int maxEqualFreq(vector<int>& nums) {
        for(int n: nums) {
            cnt[n]++;
            freq[cnt[n]]++;
        }
        for(int i=nums.size()-1;i>0;i--) {
            int n = nums[i];
            if(freq[cnt[n]]*cnt[n] == i) return i+1;
            freq[cnt[n]]--;
            cnt[n]--;
            if(freq[cnt[nums[i-1]]]*cnt[nums[i-1]] == i) return i+1;
        }
        return 1;
    }
};