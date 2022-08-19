class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> umap;
        int i = 0;
        for(auto ch:s){
            umap[ch]++;
            while(umap[s[i]] > 1){
                i++;
            }
        }
        if(i >= s.size())
            return -1;
        return i;
    }
};