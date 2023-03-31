#include <bits/stdc++.h>
using namespace std;
// tags: C++, BFS, Bit Manipulation
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1)
            return 0;
        int finalState = (1<<n) - 1;
        vector<vector<bool>> seen(n, vector<bool>(finalState+1, false));
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++) {
            q.push({i, 1<<i});
        }
        int out = 0;
        while(!q.empty()) {
            int size = q.size();
            out++;
            for(int i=0;i<size;i++) {
                auto pair = q.front();
                q.pop();
                int node = pair.first;
                int state = pair.second;
                for(auto adj: graph[node]) {
                    int newState = 1<<adj | state;
                    if(seen[adj][newState])
                        continue;
                    if(newState == finalState)
                        return out;
                    seen[adj][newState] = true;
                    q.push({adj, newState});
                }
            }
        }
        return -1;
    }
};