class Solution {
public:
    int n;
    vector<vector<int>> table;
    int helper(int i) {
        if(i == n) return 0;
        int j = i+1;
        while(j < n and table[i][1] > table[j][0])
            j++;
        int with = table[i][2] + helper(j);
        int without = helper(i+1);
        return max(with, without);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& v) {
        n = startTime.size();
        for(int i=0;i<n;i++) {
            vector<int> tmp;
            tmp.push_back(startTime[i]);
            tmp.push_back(endTime[i]);
            tmp.push_back(v[i]);
            table.push_back(tmp);
        }
        sort(table.begin(), table.end());
        cout<<table[0][0];
        return helper(0);
    }
};