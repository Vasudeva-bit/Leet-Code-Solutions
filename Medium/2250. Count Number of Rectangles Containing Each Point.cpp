class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> space(101);
        for(int i=0;i<rectangles.size();i++) {
            space[rectangles[i][1]].push_back(rectangles[i][0]);
        }
        for(int i=1;i<=100;i++) {
            sort(space[i].begin(), space[i].end());
        }
        int c;
        vector<int> ans;
        for(int i=0;i<points.size();i++) {
            c = 0;
            for(int j=points[i][1];j<=100;j++) {
                int id = lower_bound(space[j].begin(), space[j].end(), points[i][0]) - space[j].begin();
                c += space[j].size() - id;
            }
            ans.push_back(c);
        }
        return ans;
    }
};