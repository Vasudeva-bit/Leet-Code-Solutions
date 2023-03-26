#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> seen;
    vector<vector<int>> adjMat;
    int nodes = 0;
    void DFS(int n) {
        nodes++;
        seen[n] = true;
        for(auto neigh: adjMat[n]) {
            if(!seen[neigh])
                DFS(neigh);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        adjMat = vector<vector<int>>(n);
        seen = vector<bool>(n, false);
        for(auto edge: connections) {
            adjMat[edge[0]].push_back(edge[1]);
            adjMat[edge[1]].push_back(edge[0]);
        }
        int totEdges = connections.size();
        int comp = 0;
        int tot = 0;
        for(int i=0;i<n;i++) {
            if(!seen[i]) {
                DFS(i);
                tot += nodes;
                nodes = 0;
                comp++;
            }
        }
        tot -= comp;
        if((totEdges-tot) >= (comp-1)) 
            return comp-1;
        return -1;
    }
};