class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size();
        int Wlen = words.size()*len;
        unordered_map<string, int> umap;
        for(int i=0;i<words.size();i++) {
            umap[words[i]]++;
        }
        vector<int> result;
        int i = 0;
        while(i + Wlen <= s.size()) {
            if(check(umap, s.substr(i, Wlen), len))
                result.push_back(i);
            i++;
        }
        return result;
    }
    
    bool check(unordered_map<string, int> umap, string s, int len) {
        for(int j=0; j<s.size(); j+=len) {
            if(umap.find(s.substr(j, len)) != umap.end()) {
                if(--umap[s.substr(j, len)] == -1) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};