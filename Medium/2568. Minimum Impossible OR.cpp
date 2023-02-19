#include <bits/stdc++.h>;
using namespace std;
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(auto val: nums) {
            umap[val]++;
        }
        int n = 1;
        while(n < 1e10) {
            if(umap.find(n) == umap.end()) {
                return n;
            }
            n <<= 1;
        }
        return 1e10;
    }
};