class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> seen(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;
        int cZeros = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 0) cZeros++;
                if(!seen[i][j] and grid[i][j] == 1) {
                    seen[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }
        if(cZeros == n*m or cZeros == 0)
            return -1;
        int out = 0;
        while(!q.empty()) {
            auto ele = q.front();
            int i = ele.first.first;
            int j = ele.first.second;
            int dis = ele.second;
            q.pop();
            out = max(out, dis);
            if(i-1 >= 0 and !seen[i-1][j]) {
                q.push({{i-1, j}, dis+1});
                seen[i-1][j] = true;
            }
            if(j-1 >= 0 and !seen[i][j-1]) {
                q.push({{i, j-1}, dis+1});
                seen[i][j-1] = true;
            }
            if(i+1 < n and !seen[i+1][j]) {
                q.push({{i+1, j}, dis+1});
                seen[i+1][j] = true;
            }
            if(j+1 < m and !seen[i][j+1]) {
                q.push({{i, j+1}, dis+1});
                seen[i][j+1] = true;
            }
        }
        return out;
    }
};