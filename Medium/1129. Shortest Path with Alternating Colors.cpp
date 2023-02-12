class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> adjRed, adjBlue;
        vector<int> out;
        adjRed = vector<vector<int>>(n);
        adjBlue = vector<vector<int>>(n);
        out = vector<int>(n, -1);
        for(auto edge: redEdges) {
            adjRed[edge[0]].push_back(edge[1]);
        }
        for(auto edge: blueEdges) {
            adjBlue[edge[0]].push_back(edge[1]);
        }
        set<pair<int, char>> seen;
        queue<pair<pair<int, int>, char>> q;
        q.push({{0, 0}, 'a'});
        seen.insert({0, 'a'});
        while(!q.empty()) {
            int n = q.front().first.first;
            int d = q.front().first.second;
            char type = q.front().second;
            q.pop();
            if(out[n] == -1)
                out[n] = d;
            if(type != 'r') {
                for(auto neigh: adjRed[n]) {
                    if(seen.find({neigh, 'r'}) == seen.end()) {
                        seen.insert({neigh, 'r'});
                        q.push({{neigh, d+1}, 'r'});
                    }
                }
            }
            if(type != 'b') {
                for(auto neigh: adjBlue[n]) {
                    if(seen.find({neigh, 'b'}) == seen.end()) {
                        seen.insert({neigh, 'b'});
                        q.push({{neigh, d+1}, 'b'});
                    }
                }
            }
        }
        return out;
    }
};