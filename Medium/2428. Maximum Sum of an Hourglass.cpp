class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        vector<vector<int>> filter = {{1,1,1}, {0,1,0}, {1,1,1}};
        int m = grid.size();
        int n = grid[0].size();
        int maax = 0;
        for(int i=0;i<m-2;i++) {
            for(int j=0;j<n-2;j++) {
                int sum = 0;
                for(int a=0;a<3;a++) {
                    for(int b=0;b<3;b++) {
                        sum += grid[i+a][j+b]*filter[a][b];
                    }
                }
                maax = max(maax, sum);
            }
        }
        return maax;
    }
};