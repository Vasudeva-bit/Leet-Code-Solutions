#include <bits/stdc++.h>
using namespace std;
// tags: DFS, Backtracking
class Solution {
public:
    vector<int> seen;
    vector<bool> extraSeen;
    int count = 0;
    int out = -1;
    void DFS(int n, vector<int>& edges) {
        if(n != -1) {
            count++;
            if(seen[n] == -1) {
                seen[n] = count;
                extraSeen[n] = true;
                DFS(edges[n], edges);
            }
            else if(extraSeen[n]){
                out = max(out, (count)-seen[n]);
            }
            extraSeen[n] = false;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        seen = vector<int>(n, -1);
        extraSeen = vector<bool>(n, false);
        for(int i=0;i<n;i++) {
            count = 0;
            if(seen[i] == -1)
                DFS(i, edges);
        }
        return out;
    }
};