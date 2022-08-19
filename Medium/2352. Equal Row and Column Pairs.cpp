class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count = 0;
        for(int r=0;r<grid.size();r++) {
            for(int c=0;c<grid.size();c++) {
                int row = 0;
                int col = 0;
                while(row < grid.size() and col < grid.size()) {
                    if(!(grid[r][col] == grid[row][c])) {
                        count--;
                        break;
                    }
                    row++;
                    col++;
                }
                count++;
            }
        }
        return count;
    }
};