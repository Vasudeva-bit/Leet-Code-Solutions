#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<bool>> seen;
    vector<vector<int>> dist;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    bool safeDFS(int i, int j, int val){
        int row = dist.size();
        int col = dist[0].size();
        if(i < 0 || j < 0 ||i >= row || j >= col || seen[i][j])
                return false ;
        if(i == row-1 &&  j == col-1){
                return dist[i][j] >= val;
        }
        seen[i][j] = true;
        for(int x = 0;x<4;x++){
            int ni = i + dx[x];
            int nj = j + dy[x];
            if(i >= 0 && j >= 0 && i < row && j < col  && dist[i][j] >= val)
            if(safeDFS(ni, nj, val)) return true;
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> q;
        for(int r=0;r<row;r++) {
            for(int c=0;c<col;c++) {
                if(grid[r][c] == 1) {
                    q.push({r, c});
                }
            }
        }
        if(grid[0][0] == 1 or grid[row-1][col-1] == 1)
            return 0;
        while(!q.empty()){
            int f = q.front().first;
            int s = q.front().second;
            int val = grid[f][s];
            q.pop();
            
            for(int x = 0;x<4;x++){
                int i = f + dx[x];
                int j = s + dy[x];
                if(i >= 0 && j >= 0 && i < row && j < col && grid[i][j] == 0){
                        grid[i][j] = val + 1;
                        q.push({i,j});
                }else if(i >= 0 && j >= 0 && i < row && j < col){
                        grid[i][j] = min(grid[i][j],val+1);
                }
            }
        }
        dist = grid;
        int low = 0, high = 500;
        int mid;
        bool flag;
        int out = 0;
        while(low <= high) {
            seen = vector<vector<bool>>(row, vector<bool>(col));
            mid = (high-low)/2 + low;
            seen = vector<vector<bool>>(row, vector<bool>(col, false));
            if(safeDFS(0,0,mid)) {
                out = max(out, mid);
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return out-1;
    }
};