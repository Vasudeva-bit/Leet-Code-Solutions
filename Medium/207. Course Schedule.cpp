class Solution {
public:
    bool cycle(int n, vector<vector<int>>& adj){
        visited[n] = true;
        tracker[n] = true;
        for(auto it:adj[n]){
            if(visited[it] == false && cycle(it, adj))
                return true;
            else if(tracker[it] == true)
                return true;
        }
        tracker[n] = false;
        return false;
    }
    vector<bool> visited;
    vector<bool> tracker;
    bool canFinish(int n, vector<vector<int>>& pr) {
        vector<vector<int>> adj(n);
        tracker = vector<bool>(n);
        visited = vector<bool>(n);
        for(auto it:pr){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(visited[i] == false && cycle(i, adj))
                return false;
        }
        return true;
    }
};