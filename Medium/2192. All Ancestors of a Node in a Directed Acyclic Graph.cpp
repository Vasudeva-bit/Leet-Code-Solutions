class Solution {
public:
    void dfs(vector<int>& visited, int src, vector<int> adj[]) {
        visited[src] = 1;
        for(auto x:adj[src]) {
            if(!visited[x])
                dfs(visited, x, adj);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        vector<int> adj[n];
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        for(int i=0;i<n;i++) {
            vector<int> visited(n, 0);
            dfs(visited, i, adj);
            for(int j=0;j<n;j++) {
                if(i != j and visited[j]) {
                    result[j].push_back(i);
                }
            }
        }
        return result;
    }
};