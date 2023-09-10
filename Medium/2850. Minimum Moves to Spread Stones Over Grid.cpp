#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& grid) {
        int flag = true;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(grid[i][j] != 1) flag = false;
            }
        }
        if(flag) return 0;
        int out = INT_MAX;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                for(int k=0;k<3;k++) {
                    for(int l=0;l<3;l++) {
                        if(grid[i][j] > 1 and grid[k][l] == 0) {
                            grid[i][j]--;
                            grid[k][l]++;
                            int d = abs(i-k)+abs(j-l);
                            out = min(out, d+solve(grid));
                            grid[i][j]++;
                            grid[k][l]--;
                        }
                    }
                }
            }
        }
        return out;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        return solve(grid);
    }
};