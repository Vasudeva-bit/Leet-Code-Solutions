class Solution {
public:
    bool static cmp(pair<string, int> &a,
             pair<string, int> &b) {
        return a.second > b.second;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> map;
        for(int i=0;i<names.size();i++) {
            map.push_back({names[i], heights[i]});
        }
        sort(map.begin(), map.end(), cmp);
        vector<string> output;
        for(auto it:map) {
            output.push_back(it.first);
        }
        return output;
    }
};