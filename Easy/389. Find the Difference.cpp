class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> umap;
        for(auto ch:s) {
            umap[ch]++;
        }
        for(auto ch:t) {
            umap[ch]--;
            if(umap[ch] == 0)
                umap.erase(ch);
        }
        return umap.begin()->first;
    }
};