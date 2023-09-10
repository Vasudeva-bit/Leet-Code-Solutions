#include "bits/stdc++.h"
using namespace std;

const int N = 1e4+1;
const int W = 27;

vector<vector<int>> par(15, vector<int>(N, 0));
vector<vector<int>> frq(N, vector<int>(W, 0));
vector<int> lvl(N, 0);
vector<vector<pair<int, int>>> g(N);

class Solution {
public:
    void reset() {
        for(auto &i: lvl) i=0;
        for(auto &i: par)
            for(auto &j: i) j=0;
        for(auto &i: g)
            i.clear();
    }

    void dfs(int src, int parent) {
        lvl[src] = lvl[parent]+1;
        par[0][src] = parent;
        for(int j=1;j<15;j++) {
            par[j][src] = par[j-1][par[j-1][src]];
        }
        for(auto child: g[src]) {
            if(child.first == parent) continue;
            frq[child.first] = frq[src];
            frq[child.first][child.second]++;
            dfs(child.first, src);
        }
    }

    int lca(int u, int v) {
        if(lvl[u] > lvl[v]) {
            swap(u, v);
        }
        int diff = lvl[v]-lvl[u];
        for(int j=0;j<15;j++) {
            if(diff&(1<<j)) v=par[j][v];
        }
        if(u == v) return u;
        for(int j=14;j>=0;j--) {
            if(par[j][u] != par[j][v]) {
                u = par[j][u];
                v = par[j][v];
            }
        }
        return par[0][u];
    }

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        reset();
        for(auto i: edges) {
            g[i[0]+1].push_back({i[1]+1, i[2]});
            g[i[1]+1].push_back({i[0]+1, i[2]});
        }
        dfs(1, 0);
        vector<int> result;
        for(auto q: queries) {
            int u = q[0]+1;
            int v = q[1]+1;
            int a = lca(u, v);
            vector<int> f(W, 0);
            for(int j=0;j<W;j++)
                f[j] = frq[u][j] + frq[v][j] - 2*frq[a][j];
            int mx=0, sum=0;
            for(auto i: f) {
                mx = max(mx, i);
                sum += i;
            }
            result.push_back(sum-mx);
        }
        return result;
    }
};