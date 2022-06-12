class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> umap;
        int l = 0;
        int r = 0;
        int sum = 0;
        int ans = 0;
        while(r < nums.size()){
            int right = nums[r++];
            sum += right;
            umap[right]++;
            while(umap[right] > 1){
                int left = nums[l++];
                sum -= left;
                umap[left]--;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};