class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> umap;
        for(auto n:candyType) {
            umap[n]++;
        }
        return min(candyType.size()/2, umap.size());
    }
};