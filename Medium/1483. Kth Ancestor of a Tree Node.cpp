#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
public:
    vector<vector<int>> up;
    int LOG;
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        while((1<<LOG) <= n) {
            LOG++;
        }
        up = vector<vector<int>>(n, vector<int>(LOG));
        for(int v=0;v<n;v++)
            up[v][0] = parent[v];
        for(int j=1;j<LOG;j++) {
            for(int v=0;v<n;v++) {
                if(up[v][j-1] == -1) up[v][j] = -1;
                else up[v][j] = up[up[v][j-1]][j-1];
            }
        }
    }

    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<LOG;i++) {
            if((1<<i) & k) {
                node = up[node][i];
                if(node == -1) 
                    break;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */