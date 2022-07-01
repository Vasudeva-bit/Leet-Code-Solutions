class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> umap;
        for(auto ch:s) {
            umap[ch]++;
        }
        set<int> num;
        int result = 0;
        for(auto [i, j]: umap) {
            while(num.find(j) != num.end()) {
                j--;
                result++;
            }
            if(j>0) {
                num.insert(j);
            }
        }
        return result;
    }
};