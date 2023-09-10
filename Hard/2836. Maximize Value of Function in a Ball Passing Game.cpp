#include "bits/stdc++.h"
using namespace std;

const int bits = 34;
typedef long long ll;

class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size();
        vector<vector<ll>> dst(bits, vector<ll>(n));
        vector<vector<ll>> sum(bits, vector<ll>(n));
        
        for (int j = 0; j < n; j ++) {
            dst[0][j] = receiver[j];
            sum[0][j] = j + receiver[j];
        }
        for (int i = 1; i < bits; i ++) {
            for (int j = 0; j < n; j ++) {
                dst[i][j] = dst[i-1][dst[i-1][j]];
                sum[i][j] = sum[i-1][dst[i-1][j]] + sum[i-1][j] - dst[i-1][j];
            }
        }
        vector<ll> final_dst(n), final_sum(n);
        for (int j = 0; j < n; j ++) {
            final_dst[j] = j;
            final_sum[j] = j;
        }
        for (ll i = bits-1; i >= 0; i --) {
            if (((1ll << i) & k) == 0) continue;
            
            for (int j = 0; j < n; j ++) {
                final_sum[j] = sum[i][final_dst[j]] + final_sum[j] - final_dst[j];
                final_dst[j] = dst[i][final_dst[j]];
            }
        }
        ll out = 0;
        for(auto i: final_sum) out = max(out, i);
        return out;
    }
};