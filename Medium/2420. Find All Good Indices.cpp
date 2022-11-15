class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> asc(n, 1);
        vector<int> des(n, 1);
        for(int i=1;i<n;i++) {
            if(nums[i] <= nums[i-1])
                asc[i] = 1+asc[i-1];
        }
        for(int i=n-2;i>0;i--) {
            if(nums[i+1] >= nums[i])
                des[i] = 1+des[i+1];
        }
        vector<int> out;
        for(int i=k;i<n-k;i++) {
            if(asc[i-1] >= k and des[i+1] >= k)
                out.push_back(i);
        }
        return out;
    }
};