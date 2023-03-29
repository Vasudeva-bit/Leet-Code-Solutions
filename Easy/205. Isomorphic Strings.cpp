#include <bits/stdc++.h>
using namespace std;
// tags: C++, String, Hash Table
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> umap1, umap2;
        int n = s.size();
        if(t.size() != n)
            return false;
        for(int i=0;i<n;i++) {
            if(umap1.find(s[i]) == umap1.end() and umap2.find(t[i]) == umap2.end()) {
                umap1[s[i]] = t[i];
                umap2[t[i]] = s[i];
            }
            else if(umap1[s[i]] != t[i] or umap2[t[i]] != s[i])
                return false;
        }
        return true;
    }
};