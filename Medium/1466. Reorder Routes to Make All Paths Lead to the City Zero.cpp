#include <bits/stdc++.h>
using namespace std;
// tags: DFS, Graphs, Adjacency Matrices
class Solution {
public:
    int out = 0;
    vector<bool> seen;
    void DFS(int n, vector<vector<int>>& outMat, vector<vector<int>>& inMat) {
        seen[n] = true;
        for(auto adj: inMat[n]) {
            if(!seen[adj])
                DFS(adj, outMat, inMat);
        }
        for(auto adj: outMat[n]) {
            if(!seen[adj]) {
                out++;
                DFS(adj, outMat, inMat);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> outMat(n);
        vector<vector<int>> inMat(n);
        seen = vector<bool>(n, false);
        for(auto edge: connections) {
            outMat[edge[0]].push_back(edge[1]);
            inMat[edge[1]].push_back(edge[0]);
        }
        DFS(0, outMat, inMat);
        return out;
    }
};