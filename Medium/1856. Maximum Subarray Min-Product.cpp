#include "bits/stdc++.h"
using namespace std;

int mod = 1e9+7;
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        vector<pair<int, int>> st;
        long long out = 0;
        long long n = nums.size();
        vector<long long> prefix(n+1, 0);
        for(int i=0;i<n;i++) {
            prefix[i+1] = prefix[i]+nums[i];
        }
        for(int i=0;i<n;i++) {
            long long newStart = i;
            long long newVal = nums[i];
            while(st.size() != 0 and st.back().second > newVal) {
                long long tot = prefix[i]-prefix[st.back().first];
                out = max(out, tot*st.back().second);
                newStart = st.back().first;
                st.pop_back();
            }
            st.push_back({newStart, newVal});
        }
        for(auto pair: st) {
            out = max(out, (prefix[n]-prefix[pair.first])*pair.second);
        }
        return out%mod;
    }
};