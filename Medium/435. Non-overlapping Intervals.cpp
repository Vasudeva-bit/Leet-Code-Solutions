class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>&b){
        if(a[1] < b[1])return true;
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int result = 1;
        sort(intervals.begin(),intervals.end(), cmp);
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(end <= intervals[i][0]){
                result++;
                end = intervals[i][1];
            }
        }
     return intervals.size() - result;
    }
};