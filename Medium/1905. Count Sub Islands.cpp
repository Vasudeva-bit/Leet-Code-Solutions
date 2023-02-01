class Solution {
public:
    vector<vector<bool>> seen;
    int n, m;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        int count = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid2[i][j] and DFS(grid1, grid2, i, j))
                    count++;
            }
        }
        return count;
    }
    bool DFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if(i < 0 or i>= n or j < 0 or j >= m or grid2[i][j] == 0){
            return true;
        }
        if(grid1[i][j] == 0){
            return false;
        }
        grid2[i][j] = 0;
        bool a = DFS(grid1,grid2,i+1,j);
        bool b = DFS(grid1,grid2,i-1,j);
        bool c = DFS(grid1,grid2,i,j+1);
        bool d = DFS(grid1,grid2,i,j-1);
        return a and b and c and d;
    }
};