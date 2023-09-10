#include "bits/stdc++.h"
using namespace std;

class DSU {
public:
    vector<int> size;
    vector<int> parent;
    DSU(int n) {
        size = vector<int>(n, 1);
        parent = vector<int>(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int n) {
        while(parent[n] != n) {
            parent[n] = parent[parent[n]];
            n = parent[n];
        }
        return n;
    }
    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return false;
        if(size[u] < size[v]) 
            swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        return true;
    }
};
class Solution {
public:
    bool static comparator(vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int i = 0;
        for(auto &edge: edges) {
            edge.push_back(i);
            i++;
        }
        sort(begin(edges), end(edges), comparator);
        DSU dsu(n);
        int mst_cost = 0;
        for(auto &edge: edges) {
            if(dsu.merge(edge[0], edge[1]))
                mst_cost += edge[2];
        }
        vector<int> critical, psuedo;
        for(auto &edge_out: edges) {
            dsu = DSU(n);
            // critical edges
            int cost = 0;
            for(auto &edge_in: edges) {
                if(edge_out[3] != edge_in[3]  and dsu.merge(edge_in[0], edge_in[1]))
                    cost += edge_in[2];
            }
            if(*max_element(begin(dsu.size), end(dsu.size)) != n or cost > mst_cost) {
                critical.push_back(edge_out[3]);
                continue;
            }
            // psuedo edges
            cost = edge_out[2];
            dsu = DSU(n);
            dsu.merge(edge_out[0], edge_out[1]);
            for(auto &edge_in: edges) {
                if(dsu.merge(edge_in[0], edge_in[1]))
                    cost += edge_in[2];
            }
            if(cost == mst_cost)
                psuedo.push_back(edge_out[3]);
        }
        vector<vector<int>> out(2);
        out[0] = critical;
        out[1] = psuedo;
        return out;
    }
};