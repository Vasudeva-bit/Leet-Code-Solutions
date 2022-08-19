class Solution {
public:
    int mergeSort(vector<int> & n, int l, int r) {
        int count = 0;
        if(l >= r)
            return 0;
        int mid = l + (r-l)/2;
        count += mergeSort(n, l, mid);
        count += mergeSort(n, mid+1, r);
        count += merge(n, l, mid, r);
        return count;
    }
    int merge(vector<int> & n, int l, int mid, int r) {
        int i = l;
        int k = 0;
        int j = mid+1;
        vector<int> temp(r-l+1);
        int count = 0;
        while(i <= mid and j <= r) {
            if((long) n[i] > 2*(long) n[j]) {
                count += mid-i+1;
                
                j++;
                
            }
            else {
                i++;
            }
        }
        i = l;
        j = mid + 1;
        while(i <= mid and j <= r) {
            if(n[i] < n[j]) {
                temp[k++] = n[i++];
            }
            else {
                temp[k++] = n[j++];
            }
        }
        while(i <= mid) {
            temp[k++] = n[i++];
        }
        while(j <= r) {
            temp[k++] = n[j++];
        }
        
        for(int i=l;i<r;i++) {
            n[i] = temp[i-l];
        }
        return count;
        
    }
    int reversePairs(vector<int>& nums) {        
        return mergeSort(nums, 0, nums.size()-1);
    }
};