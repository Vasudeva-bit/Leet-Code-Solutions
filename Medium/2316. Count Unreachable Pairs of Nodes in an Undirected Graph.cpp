class Solution {
public:
    void ConnectedNodes(int src, vector<int> adj[], vector<int>& visited, long long& nodes) {
        visited[src] = 1;
        nodes ++;
        for(auto n:adj[src]) {
            if(!visited[n]) {
                ConnectedNodes(n, adj, visited, nodes);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long count = 0;
        int x = n;
        vector<int> adj[n];
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(x, 0);
        for(int i=0;i<x;i++) {
            if(!visited[i]) {
                long long nodes = 0;
                ConnectedNodes(i, adj, visited, nodes);
                count += nodes*(n-nodes);
                n -= nodes;
            }
        }
        return count;
    }
};