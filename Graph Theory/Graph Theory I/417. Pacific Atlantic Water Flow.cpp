class Solution {
public:
    int n, m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        n = h.size();
        m = h[0].size();
        set<pair<int, int>> pac, atl;
        for(int i=0;i<n;i++) {
            DFS(i, 0, pac, h[i][0], h);
            DFS(i, m-1, atl, h[i][m-1], h);
        }
        for(int j=0;j<m;j++) {
            DFS(0, j, pac, h[0][j], h);
            DFS(n-1, j, atl, h[n-1][j], h);
        }
        vector<vector<int>> out;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(pac.find({i, j}) != pac.end() and atl.find({i, j}) != atl.end())
                    out.push_back({i, j});
            }
        }
        return out;
    }
    void DFS(int i, int j, set<pair<int, int>>& seen, int prev, vector<vector<int>>& h) {
        if(i < 0 or j < 0 or i >= n or j >= m or seen.find({i, j}) != seen.end() or h[i][j] < prev) {
            return;
        }
        seen.insert({i, j});
        DFS(i+1, j, seen, h[i][j], h);
        DFS(i, j+1, seen, h[i][j], h);
        DFS(i-1, j, seen, h[i][j], h);
        DFS(i, j-1, seen, h[i][j], h);
    }
};