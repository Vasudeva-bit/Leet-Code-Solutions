class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> umap;
        for(auto it:arr) {
            if((it%2 == 0 and umap[it/2] > 0) or umap[it*2])
                return true;
            umap[it]++;
        }
        return false;
    }
};