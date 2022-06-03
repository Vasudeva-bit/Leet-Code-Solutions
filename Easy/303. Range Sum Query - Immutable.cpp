class NumArray {
public:
    vector<int> tem;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        tem = vector<int>(n+1, 0);
        tem[1] = nums[0];
        for(int i=1;i<n;i++){
            tem[i+1] = nums[i] + tem[i];
        }
    }
    
    int sumRange(int left, int right) {
        return tem[right+1] - tem[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */