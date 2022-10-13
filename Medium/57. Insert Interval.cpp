class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0)
            return {newInterval};
        vector<vector<int>> output;
        int i = 0;
        while(i < intervals.size() and intervals[i][0] < newInterval[0]) {
            output.push_back(intervals[i]);
            i++;
        }
        if(output.size() == 0)
            output.push_back(newInterval);
        else if(output[output.size()-1][1] < newInterval[0])
            output.push_back(newInterval);
        else if(output[output.size()-1][1] < newInterval[1])
            output[output.size()-1][1] = newInterval[1];
        while(i < intervals.size()) {
            if(output.size() == 0)
                output.push_back(newInterval);
            else if(output[output.size()-1][1] < intervals[i][0])
                output.push_back(intervals[i]);
            else if(output[output.size()-1][1] < intervals[i][1])
                output[output.size()-1][1] = intervals[i][1];
            i++;
        }
        return output;
    }
};