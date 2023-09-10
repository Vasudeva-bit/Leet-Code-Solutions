#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    long long n;
    vector<long long> pre(vector<vector<int>>& grid) {
        long long sum = 0;
        vector<long long> prefix(n);
        for(long long i=0;i<n;i++) {
            sum += grid[1][i];
            prefix[i] = sum;   
        }
        return prefix;
    }
    
    vector<long long> suf(vector<vector<int>>& grid) {
        long long sum = 0;
        vector<long long> suffix(n);
        for(long long i=n-1;i>=0;i--) {
            sum += grid[0][i];
            suffix[i] = sum;
        }
        return suffix;
    }

    long long gridGame(vector<vector<int>>& grid) {
        n = grid[0].size();
        vector<long long> prefix;
        vector<long long> suffix;
        prefix = pre(grid);
        suffix = suf(grid);
        long long out = LLONG_MAX;
        for(int i=0;i<n;i++) {
            out = min(out, max(suffix[i]-(long long)grid[0][i], prefix[i]-(long long)grid[1][i]));
        }
        return out;
    }
};