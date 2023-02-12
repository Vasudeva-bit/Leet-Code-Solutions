// Method 1: Using BFS
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
// Method 2: Using BFS
class Solution {
public:
    int n, m;
    vector<vector<bool>> seen;
    queue<pair<pair<int, int>, int>> q;
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        seen = vector<vector<bool>>(n, vector<bool>(n, false));
        int cZeros = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1) {
                    seen[i][j] = true;
                    q.push({{i, j}, 0});
                }
                else
                    cZeros++;
            }
        }
        if(cZeros == n*n or cZeros == 0)
            return -1;
        return BFS(grid);
    }
    int BFS(vector<vector<int>>& grid) {
        int out = 0;
        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int d = q.front().second;
            q.pop();
            out = max(out, d);
            vector<int> dx = {1, -1, 0, 0};
            vector<int> dy = {0, 0, -1, 1};
            for(int t=0;t<4;t++) {
                int ni = i+dx[t];
                int nj = j+dy[t];
                if(ni < 0 or nj < 0 or ni >= n or nj >= m or seen[ni][nj])
                    continue;
                seen[ni][nj] = true;
                q.push({{ni, nj}, d+1});
            }
        }
        return out;
    }
};