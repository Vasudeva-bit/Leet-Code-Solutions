class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> out;
        auto str = get_pattern(pattern);
        for(auto w:words) {
            if(str == get_pattern(w)) {
                out.push_back(w);
            }
        }
        return out;
    }
    vector<int> get_pattern(string str) {
        vector<int> out;
        int c = 0;
        unordered_map<char, int> umap;
        for(auto i:str) {
            if(umap.find(i) != umap.end()) {
                out.push_back(umap[i]);
            }
            else {
                c += 1;
                umap[i] = c;
                out.push_back(c);
            }
        }
        return out;
    }
};