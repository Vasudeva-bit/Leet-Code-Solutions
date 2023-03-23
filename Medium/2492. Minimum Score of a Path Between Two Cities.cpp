#include <bits/stdc++.h>
using namespace std;
typedef struct unionFind {
    vector<int> parent;
    vector<int> size;
    unionFind(int n) {
        size = vector<int>(n+1, 1);
        for(int i=1;i<=n;i++) {
            parent.push_back(i);
        }
    }
    int find(int n) {
        if(parent[n] == n)
            return n;
        return parent[n]=find(parent[n]);
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if(x != y) {
            if(size[x] < size[y]) swap(x, y);
                parent[y] = parent[x];
            size[x] += size[y];
        }
    }
} unionFind;
class Solution {
public:
    vector<bool> seen;
    int score = INT_MAX;
    void DFS(int n, vector<vector<vector<int>>>& adjMat) {
        for(auto adjVectr: adjMat[n]) {
            if(!seen[adjVectr[0]]) {
                seen[adjVectr[0]] = true;
                DFS(adjVectr[0], adjMat);
            }
            score = min(score, adjVectr[1]);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>> adjMat(n+1);
        seen = vector<bool>(n+1, false);
        for(auto vectr: roads) {
            adjMat[vectr[0]].push_back({vectr[1], vectr[2]});
            adjMat[vectr[1]].push_back({vectr[0], vectr[2]});
        }
        DFS(1, adjMat);
        return score;
    }
};