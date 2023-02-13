class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        unordered_map<int, pair<int, int>> umap;
        for(int i=0;i<n;i++) {
            int curVal = 0;
            for(int j=0;j<min(31, n-i);j++) {
                curVal <<= 1;
                curVal += int(s[i+j]-'0');
                if(umap.find(curVal) == umap.end()) {
                    umap[curVal] = {i, i+j};
                }
                else if(j < umap[curVal].second-umap[curVal].first)
                    umap[curVal] = {i, i+j};
            }
        } 
        vector<vector<int>> out;
        for(auto q: queries) {
            int val = q[0]^q[1];
            if(umap.find(val) != umap.end()) {
                out.push_back({umap[val].first, umap[val].second});
            }
            else {
                out.push_back({-1, -1});
            }
        }
        return out;
    }
};