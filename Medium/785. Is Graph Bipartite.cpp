class Solution {
public:
    vector<int> color;
    bool is_Bipartite = true;
    void coloring(int idx, int cur, vector<vector<int>>& graph){
        if(color[idx] != -1 && color[idx] != cur){
            is_Bipartite = false;
            return;
        }
        if(color[idx] != -1)
            return;
        color[idx] = cur;
        for(auto it:graph[idx]){
            coloring(it, cur xor 1, graph);
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // Traverse through the graph
        int n = graph.size();
        color = vector<int>(n, -1);
        for(int i=0;i<n;i++){
            if(color[i] == -1)
                coloring(i, 0, graph);
        }
        return is_Bipartite;
    }
};