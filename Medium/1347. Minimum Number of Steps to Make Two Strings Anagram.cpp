class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> umap;
        for(auto ch:s) umap[ch]++;
        for(auto ch:t) umap[ch]--;
        int sum = 0;
        for(auto it:umap) {
            sum +=abs(it.second);
        }
        return sum/2;
    }
};