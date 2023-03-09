#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
        if(grid[0][1] > 1 and grid[1][0] > 1) return -1;
        int R = grid.size();
        int C = grid[0].size();
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        vector<vector<bool>> seen(R, vector<bool>(C, false));
        pq.push({0, 0, 0});
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int time = curr[0];
            int r = curr[1];
            int c = curr[2];
            if(seen[r][c]) continue;
            seen[r][c] = true;
            if(r == R-1 and c == C-1)
                return time;
            for(int t=0;t<4;t++) {
                int nr = dx[t]+r;
                int nc = dy[t]+c;
                if(nc < 0 or nr < 0 or nc == C or nr == R or seen[nr][nc]) continue;
                if(grid[nr][nc] <= time+1) {
                    pq.push({time+1, nr, nc});
                }
                else {
                    int diff = grid[nr][nc]-time;
                    if(diff%2 == 1) {
                        pq.push({grid[nr][nc], nr, nc});
                    }
                    else {
                        pq.push({grid[nr][nc]+1, nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};