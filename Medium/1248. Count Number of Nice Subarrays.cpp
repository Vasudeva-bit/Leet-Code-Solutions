#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(int &n: nums) {
            n %= 2;
        }
        int out = 0;
        umap[0]++;
        int cnt = 0;
        for(int &n: nums) {
            cnt += n;
            out += umap[cnt-k];
            umap[cnt]++;
        }
        return out;
    }
};