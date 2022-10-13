class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int ans=0;
        unordered_map<int, int> umap;
        int n = nums.size();
        umap[nums[n-1]] = 1;
        for(int i=n-2;i>1;i--) {
            for(int j=i-1;j>0;j--) {
                for(int k=j-1;k>=0;k--) {
                    if(umap.count(nums[i]+nums[j]+nums[k]))
                        ans += umap[nums[i]+nums[j]+nums[k]];
                }
            }
            umap[nums[i]] += 1;
        }
        return ans;
    }
};