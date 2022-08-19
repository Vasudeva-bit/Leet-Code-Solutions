class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> umap;
        int c = 0;
        for(auto i:nums) {
            if(umap[i] < 1 and i != 0) {
                c++;
                umap[i]++;
            }
        }
        return c;
    }
};