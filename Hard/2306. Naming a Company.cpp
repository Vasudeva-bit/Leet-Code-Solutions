class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<vector<long long>> count(26, vector<long long>(26, 0));
        unordered_map<string, long long> umap;
        for(auto idea: ideas) {
            umap[idea] = true;
        }
        for(auto idea: ideas) {
            int idx = idea[0]-'a';
            string word = idea.substr(1);
            for(int i=0;i<26;i++) {
                if(umap.count((char)('a'+i)+word) == 0)
                    count[idx][i]++;
            }
        }
        long long out = 0;
        for(int i=0;i<26;i++) {
            for(int j=0;j<26;j++) {
                if(i == j) continue;
                if(count[i][j] != 0) 
                    out += count[i][j] * count[j][i];
            }
        }
        return out;
    }
};