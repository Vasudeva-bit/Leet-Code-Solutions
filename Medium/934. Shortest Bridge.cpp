class Solution {
public:
    int n, m;
    queue<pair<pair<int, int>, int>> Q;
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1) {
                    DFS(i, j, grid);
                    return BFS(grid);
                }
            }
        }
        return -1;
    }
    int BFS(vector<vector<int>>& grid) {
        while(!Q.empty()) {
            int i = Q.front().first.first;
            int j = Q.front().first.second;
            int d = Q.front().second;
            Q.pop();
            vector<int> dx = {1, -1, 0, 0};
            vector<int> dy = {0, 0, -1, 1};
            for(int t=0;t<4;t++) {
                int ni = i+dx[t];
                int nj = j+dy[t];
                if(ni < 0 or nj < 0 or ni >= n or nj >= m or grid[ni][nj] == 2)
                    continue;
                if(grid[ni][nj] == 1)
                    return d;
                grid[ni][nj] = 2;
                Q.push({{ni, nj}, d+1});
            }
        }
        return -1;
    }
    void DFS(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 or j < 0 or i >= n or j >= m or grid[i][j] == 0 or grid[i][j] == 2)
            return;
        grid[i][j] = 2;
        Q.push({{i, j}, 0});
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        for(int t=0;t<4;t++) {
            int ni = i+dx[t];
            int nj = j+dy[t];
            DFS(ni, nj, grid);
        }
    }
};