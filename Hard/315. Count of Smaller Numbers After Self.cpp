class Solution {
public:
   void merge(vector<pair<int, int>> &v, int left, int mid, int right, vector<int> &count){
        vector<pair<int,int>> temp(right - left + 1);
        int i=left;
        int j=mid+1;
        int k=0;
        while(i<=mid && j<=right){
            if(v[i].first <= v[j].first){
                temp[k++] = v[j++];
            }
            else{
                count[v[i].second] += right-j+1;
                temp[k++] = v[i++];
            }
        }
        while(i<=mid){
            temp[k++] = v[i++];
        }
        while(j<=right){
            temp[k++] = v[j++];
        }
        for(int i=left;i<=right;i++){
            v[i] = temp[i-left]; 
        }
    }
    
    void mergeSort(vector<pair<int, int>>& v, int l, int r, vector<int>& count) {
        if(l<r){
            int mid = l + (r-l)/2;
            mergeSort(v, l, mid, count);
            mergeSort(v, mid+1, r, count);
            merge(v, l, mid, r, count);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        vector<pair<int, int>> v;
        for(int i=0;i<nums.size();i++) {
            pair<int, int> p;
            p.first = nums[i];
            p.second = i;
            v.push_back(p);
        }
        mergeSort(v, 0, nums.size()-1, count);
        return count;
    }
};