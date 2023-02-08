class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int n, m;
        n = mat.size();
        m = mat[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j] == 0)
                    q.push({i, j});
                else
                    mat[i][j] = INT_MIN;
            }
        }
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(!(nx < 0 or ny < 0 or nx >= n or ny >= m) and mat[nx][ny] == INT_MIN) {
                    mat[nx][ny] = mat[x][y]+1;
                    q.push({nx, ny});
                }
            }
        }
        return mat;
    }
};