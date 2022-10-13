class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n < 2)
            return intervals;
        vector<vector<int>> output;
        sort(intervals.begin(), intervals.end());
        output.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++) {
            auto it = intervals[i];
            if(it[0] > output.back()[1])
                output.push_back(it);
            else if(it[1] > output.back()[1])
                output[output.size()-1][1] = it[1];
        }
        return output;
    }
};