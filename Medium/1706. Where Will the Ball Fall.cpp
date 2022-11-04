class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n_r, n_c;
        n_r = grid.size();
        n_c = grid[0].size();
        vector<int> ans;
        for(int i=0;i<n_c;i++) ans.push_back(i);
        for(int r=0;r<n_r;r++) {
            for(int c=0;c<n_c;c++) {
                if(ans[c] == -1) continue;
                int col = ans[c];
                int col_nex = col + grid[r][col];
                if(col_nex < 0 or col_nex >= n_c or grid[r][col_nex] == -1*(grid[r][col])) {
                    ans[c] = -1;
                    continue;
                } 
                ans[c] += grid[r][col];
            }
        }
        return ans;
    }
};