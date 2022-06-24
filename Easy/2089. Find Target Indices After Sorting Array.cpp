class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l=0;
        int r=nums.size()-1;
        int mid;
        while(l<=r){
            mid = (r-l)/2 + l;
            if(nums[mid] == target)
                break;
            else if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        l = mid;
        r = mid;
        if(mid >= 0 && mid < nums.size() && nums[mid] == target){
            while(l >= 0){
                if(nums[l] == target) l--;
                else break;
            }
            while(r < nums.size()){
                if(nums[r] == target) r++;
                else break;
            }
            vector<int> result;
            for(int i=l+1;i<r;i++)
                result.push_back(i);
            return result;
        }
        return vector<int>({});
    }
};