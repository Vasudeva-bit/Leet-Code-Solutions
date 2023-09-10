#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> topSort(queue<int>& q, vector<vector<int>> &out_edges, vector<int> &in_deg) {
        vector<int> order;
        while(!q.empty()) {
            int node = q.front();
            order.push_back(node);
            q.pop();
            for(auto next: out_edges[node]) {
                in_deg[next]--;
                if(!in_deg[next]) {
                    q.push(next);
                }
            }
        }
        return order;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<int> heads, tails;
        for(int i=0;i<m;i++) {
            heads.push_back(n+2*i);
            tails.push_back(n+2*i+1);
        }
        vector<vector<int>> out_edges(n+2*m);
        vector<int> in_deg(n+2*m);
        int g = group.size();
        
        for(int i=0;i<g;i++) {
            int item = i;
            int grp = group[i];
            auto bi = beforeItems[i];
            
            if(grp != -1) {
                int head = heads[grp];
                int tail = tails[grp];
                out_edges[head].push_back(item);
                in_deg[item]++;
                out_edges[item].push_back(tail);
                in_deg[tail]++;
            }
            
            for(auto before: bi) {
                int from = group[before];
                int to = group[item];
                bool same_group = from == to;
                int out = (same_group or from == -1)?before:tails[from];
                to = (same_group or to == -1)?item:heads[to];
                out_edges[out].push_back(to);
                in_deg[to]++;
            }
        }
        
        vector<int> starts;
        vector<int> order;
        
        for(int i=0;i<n+2*m;i++) {
            if(!in_deg[i])
                starts.push_back(i);
        }
        
        for(auto start: starts) {
            queue<int> q;
            q.push(start);
            auto add = topSort(q, out_edges, in_deg);
            for(auto val: add) {
                if(val < n)
                    order.push_back(val);
            }
        }
        if(order.size() != n) return {};
        return order;
    }
};