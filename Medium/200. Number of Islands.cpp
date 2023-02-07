// Method 1: Without Union Find
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0; j<grid[0].size();j++) {
                if(grid[i][j] == '1') {
                    result++;
                    dfs(grid, i, j);
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i<0 or j<0 or j>=grid[0].size() or i>=grid.size() or grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};
// With Union Find
struct DSU {
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        size = vector<int>(n, 1);
        for(int i=0;i<n;i++)
            parent.push_back(i);
    }
    int Find(int n) {
        if(parent[n] == n)
            return n;
        return parent[n] = Find(parent[n]);
    }
    bool unionSet(int x, int y) {
        x = Find(x);
        y = Find(y);
        if(x == y)
            return false;
        if(size[x] > size[y]) swap(x, y);
        size[y] += size[x];
        parent[x] = y;
        return true;
    }
};
class Solution {
public:
    int n, m;
    int countIslands = 0;
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        DSU dsu(n*m+n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1') {
                    countIslands++;
                    unionAround(i, j, dsu, grid);
                }
            }
        }
        return countIslands;
    }
    void unionAround(int x, int y, DSU& dsu, vector<vector<char>>& grid) {
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        int i = (x*m + y);
        for(int t=0;t<4;t++) {
            int nx = x+dx[t];
            int ny = y+dy[t];
            int j = (nx*m+ny);
            if(nx >= 0 and nx < n and ny >= 0 and ny < m and grid[nx][ny] == '1' and dsu.unionSet(i, j)) countIslands--;
        }
    }
};