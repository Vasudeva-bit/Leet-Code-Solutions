class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> umap;
        int val = 97;
        for(auto ch:key) {
            if(umap.find(ch) == umap.end() && ch != ' ') {
                umap[ch] = char(val);
                val++;
            }
        }
        string result = "";
        for(auto ch:message) {
            if(ch != ' ')
                result += umap[ch];
            else
                result += " ";
        }
        return result;
    }
};