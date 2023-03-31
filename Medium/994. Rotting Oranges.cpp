#include <bits/stdc++.h>
using namespace std;
// tags: C++, BFS, Greedy
class Solution {
public:
    vector<vector<int>> seen;
    int row, col;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    void BFS(int r, int c, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({r, c});
        int count = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int p=0;p<size;p++) {
                auto pair = q.front();
                int i = pair.first;
                int j = pair.second;
                q.pop();     
                for(int t=0;t<4;t++) {
                    int ni = i+dx[t];
                    int nj = j+dy[t];
                    if(ni < 0 or nj < 0 or ni >= row or nj >= col or grid[ni][nj] == 0 or seen[ni][nj] < count) {
                        continue;
                    }
                    seen[ni][nj] = count;
                    q.push({ni, nj});
                }
            }
            count++;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        seen = vector<vector<int>>(row, vector<int>(col, INT_MAX));
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j] == 0)
                    seen[i][j] = 0;
                else if(grid[i][j] == 2) {
                    seen[i][j] = 0;
                    BFS(i, j, grid);
                }
            }
        }
        int out = INT_MIN;
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                out = max(out, seen[i][j]);
            }
        }
        if(out == INT_MAX) return -1;
        return out;
    }
};