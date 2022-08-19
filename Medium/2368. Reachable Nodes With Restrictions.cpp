class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);
        vector<int> permit(n, 1);
        for(auto pair:edges) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        for(auto i:restricted) {
            permit[i] = 0;
        }
        dfs(0, visited, adj, permit);
        return accumulate(visited.begin(), visited.end(), 0);
    }
    
    void dfs(int node, vector<int>& visited, vector<vector<int>>& edges, vector<int>& permit) {
        visited[node] = 1;
        for(auto i:edges[node]) {
            if(visited[i] == 0 and permit[i] == 1)
                dfs(i, visited, edges, permit);
        }
    }
};