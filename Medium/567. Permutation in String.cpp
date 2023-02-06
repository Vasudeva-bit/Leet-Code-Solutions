class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        unordered_map<char, int> freq;
        for(auto ch:s1) {
            freq[ch]++;
        }
        for(int i=0;i<=(s2.size()-s1.size());i++) {
            unordered_map<char, int> umap = freq;
            for(int j=i;j<(i+s1.size());j++) {
                char ch = s2[j];
                umap[ch]--;
                if(umap[ch] == 0)
                    umap.erase(ch);
            }
            if(umap.size() == 0)
                return true;
        }
        return false;
    }
};