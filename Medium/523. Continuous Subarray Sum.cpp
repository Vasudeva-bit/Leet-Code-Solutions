class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        umap[0] = -1;
        int sum = 0;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            if(k != 0) sum %= k;
            if(umap.find(sum) != umap.end()) {
                if(i - umap[sum] > 1)
                    return true;
            }
            else
            umap[sum] = i;
        }
        return false;
    }
};