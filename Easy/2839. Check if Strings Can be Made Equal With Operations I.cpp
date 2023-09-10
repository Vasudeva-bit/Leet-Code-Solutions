#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_map<string, int> umap;
        umap[s1]++;
        umap[s2]++;
        if(s1[0] != s1[2]) {
            swap(s1[0], s1[2]);
            umap[s1]++;
        }
        if(s1[1] != s1[3]) { 
            swap(s1[1], s1[3]);
            umap[s1]++;
        }
        if(s2[0] != s2[2]) {
            swap(s2[0], s2[2]);
            umap[s2]++;
        }
        if(s2[1] != s2[3]) {
            swap(s2[1], s2[3]);
            umap[s2]++;
        }
        for(auto pair: umap) {
            if(pair.second > 1) return true;
        }
        return false;
    }
};