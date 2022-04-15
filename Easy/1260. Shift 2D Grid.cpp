class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> result(r, vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int new_place = ((i*c)+j+k)%(r*c);
                int new_r = new_place/c;
                int new_j = new_place%c;
                result[new_r][new_j] = grid[i][j];
            }
        }
        return result;
    }
};
