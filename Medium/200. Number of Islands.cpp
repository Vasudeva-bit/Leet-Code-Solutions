class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0; j<grid[0].size();j++) {
                if(grid[i][j] == '1') {
                    result++;
                    dfs(grid, i, j);
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i<0 or j<0 or j>=grid[0].size() or i>=grid.size() or grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};