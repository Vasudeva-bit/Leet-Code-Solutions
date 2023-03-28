#include <bits/stdc++.h>
using namespace std;
// tags: Graphs, Adjacency Matrix, In Degree
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adjMat(n);
        for(auto road: roads) {
            adjMat[road[0]].push_back(road[1]);
            adjMat[road[1]].push_back(road[0]);
        }
        vector<int> vectr(n);
        for(int i=0;i<n;i++) {
            vectr[i] = adjMat[i].size();
        }
        int out = INT_MIN;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                vector<int> adj = adjMat[i];
                if(find(adj.begin(), adj.end(), j) == adj.end())
                    out = max(out, vectr[i]+vectr[j]);
                else
                    out = max(out, vectr[i]+vectr[j]-1);
            }
        }
        return out;
    }
};