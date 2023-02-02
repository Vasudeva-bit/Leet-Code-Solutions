class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 or grid[n-1][n-1] == 1)
            return -1;
        vector<vector<bool>> seen = vector<vector<bool>>(n, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        seen[0][0] = true;
        vector<int> dx = {1, -1, 0, 0, 1, -1, 1, -1};
        vector<int> dy = {0, 0, 1, -1, 1, -1, -1, 1};
        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            if(i == n-1 and j == n-1)
                return dis;
            for(int t=0;t<8;t++) {
                int nx = i+dx[t];
                int ny = j+dy[t];
                if(nx < 0 or ny < 0 or nx >= n or ny >= n)
                    continue;
                if(grid[nx][ny] == 0 and !seen[nx][ny]) {
                    seen[nx][ny] = true;
                    q.push({{nx, ny}, dis+1});
                }
            }
        }
        return -1;
    }
};