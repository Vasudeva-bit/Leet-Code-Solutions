class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int out = 0;
        unordered_map<int, int> umap;
        int prev = 0;
        int sum = 0;
        for(int i=0;i<n;i++) {
            umap[fruits[i]]++;
            sum++;
            if(umap.size() == 2)
                out = max(out, sum);
            while(umap.size() > 2) {
                umap[fruits[prev]]--;
                sum--;
                if(umap[fruits[prev]] == 0)
                    umap.erase(fruits[prev]);
                prev++;
            }
        }
        return max(out, sum);
    }
};