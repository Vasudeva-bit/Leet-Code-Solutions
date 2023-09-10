#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
    int closest(set<int>& st, int idx) {
        int out = INT_MAX;
        int ans = -1;
        for(auto s: st) {
            if(abs(s-idx) < out) {
                ans = s;
                out = abs(s-idx);
            }
        }
        return ans;
    }
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n = queries.size();
        for (int i=0; i<n; ++i)
            queries[i].push_back(i);
        sort(begin(queries), end(queries), cmp);
        sort(begin(rooms), end(rooms), cmp);
        int i = 0;
        vector<int> out(n);
        set<int> st;
        for(int i=0,j=0;i<n;i++) {
            for(;j<rooms.size() and rooms[j][1] >= queries[i][1];j++)
                st.insert(rooms[j][0]);
            auto it = st.lower_bound(queries[i][0]);
            int id1 = it == begin(st)? -1: *(prev(it));
            int id2 = it == end(st)? -1: *it;
            out[queries[i][2]] = min(id1, id2) == -1? max(id1, id2):abs(queries[i][0] - id1) <= abs(queries[i][0] - id2) ? id1 : id2;
        }
        return out;
    }
};