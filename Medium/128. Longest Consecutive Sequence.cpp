class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> umap(nums.begin(),nums.end());
        int result = 0;
        for(int it:nums) {
            if(find(umap.begin(),umap.end(),it) == umap.end()) continue;
            int prev = it-1; int next = it+1;
            while(find(umap.begin(),umap.end(),prev) != umap.end()) prev--;
            while(find(umap.begin(),umap.end(),next) != umap.end()) next++;
            result = max(result, next-prev-1);
            umap.erase(it);
        }
        return result;
    }
};