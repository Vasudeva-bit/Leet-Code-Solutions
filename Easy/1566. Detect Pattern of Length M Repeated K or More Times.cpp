class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int pat = 0;
        for(int i=0;i+m<arr.size();i++) {
            if(arr[i] == arr[i+m])
                pat++;
            if(arr[i] != arr[i+m])
                pat=0;
            if(pat == m*(k-1))
                return true;
        }
        return false;
    }
};