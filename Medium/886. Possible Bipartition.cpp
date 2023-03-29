#include <bits/stdc++.h>
using namespace std;
// tags: C++, BFS, Adjacency Matrix
class Solution {
public:
    bool BFS(int n, vector<int>& seen, vector<vector<int>>& adjMat) {
        queue<int> q;
        q.push(n);
        seen[n] = 1;
        while(!q.empty()) {
            int val = q.front();
            q.pop();
            int color = seen[val];
            for(auto adj: adjMat[val]) {
                if(seen[adj] != -1) {
                    if(seen[adj] == color)
                        return false;
                }
                else {
                    seen[adj] = 1-color;
                    q.push(adj);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjMat(n+1);
        for(auto dislike: dislikes) {
            adjMat[dislike[0]].push_back(dislike[1]);
            adjMat[dislike[1]].push_back(dislike[0]);
        }
        vector<int> seen(n+1, -1);
        for(int i=1;i<=n;i++) {
            if(seen[i] == -1) {
                if(!BFS(i, seen, adjMat))
                    return false;
            }
        }
        return true;
    }
};