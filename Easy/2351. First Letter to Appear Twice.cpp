class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> umap;
        for(int i=0;i<s.size();i++) {
            umap[s[i]]++;
            if(umap[s[i]] > 1)
                return s[i];
        }
        return 'a';
    }
};