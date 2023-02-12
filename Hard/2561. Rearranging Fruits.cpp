class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> umap1, umap2;
        int n = basket1.size();
        int minVal = INT_MAX;
        for(int i=0;i<n;i++) {
            umap1[basket1[i]]++;
            umap2[basket2[i]]++;
            minVal = min(minVal, min(basket2[i], basket1[i]));
        }
        vector<int> toSwap;
        for(auto ele: umap1) {
            int diff = abs(ele.second-umap2[ele.first]);
            if(diff%2 != 0)
                return -1;
            diff /= 2;
            while(diff--) {
                toSwap.push_back(ele.first);
            }
            umap1[ele.first] = 0;
            umap2[ele.first] = 0;
        }
        for(auto ele: umap2) {
            int diff = abs(ele.second-umap1[ele.first]);
            if(diff%2 != 0)
                return -1;
            diff /= 2;
            while(diff--) {
                toSwap.push_back(ele.first);
            }
            umap1[ele.first] = 0;
            umap2[ele.first] = 0;
        }
        long long cost = 0;
        cout<<toSwap.size();
        sort(toSwap.begin(), toSwap.end());
        for(int i=0;i<toSwap.size()/2;i++) {
            cost += min(2*minVal, toSwap[i]);
        }
        return cost;
    }
};