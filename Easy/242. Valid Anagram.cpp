class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> umap;
        for(auto i:s){
            umap[i]++;
        }
        for(auto i:t){
            umap[i]--;
            if(umap[i] == 0)
                umap.erase(i);
        }
        if(umap.empty())
            return true;
        else
            return false;
    }
};