class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> umap;
        int out = INT_MAX;
        for(auto ch:t) {
            umap[ch]++;
        }
        int i=0;
        int j=0;
        int index=0;
        int counter=t.size();
        while(j < s.size()) {
            if(umap[s[j]] > 0)
                counter--;
            umap[s[j]]--;
            j++;
            while(counter == 0) {
                if(j-i < out) {
                    out = j-i;
                    index = i;
                }
                umap[s[i]]++;
                if(umap[s[i]] > 0)
                    counter++;
                i++;
            }
        }
        if(out == INT_MAX)
            return "";
        else {
            return s.substr(index, out);
        }
    }
};