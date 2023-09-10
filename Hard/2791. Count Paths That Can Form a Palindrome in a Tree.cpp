#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long dfs(int x, int mask, const string &s, const vector<vector<int>>& edges, unordered_map<int, int>& umap) {
        long long r = 0;
        if(x) {
            mask ^= 1<<(s[x]-'a');
            for(int i=1<<25;i;i>>=1) {
                if(umap.count(mask^i)) {
                    r += umap[mask^i];
                }
            }
            r += umap[mask]++;
        }
        for(int adj: edges[x]) {
            r += dfs(adj, mask, s, edges, umap);
        }
        return r;
    }
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        const int n = s.length();
        vector<vector<int>> edges(n);
        for(int i=1;i<n;i++) {
            edges[parent[i]].push_back(i);
        }
        unordered_map<int, int> umap;
        umap[0] = 1;
        return dfs(0, 0, s, edges, umap);
    }
};