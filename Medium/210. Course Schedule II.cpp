class Solution {
public:
    set<int> seen;
    set<int> cycle;
    vector<int> out;
    vector<int> findOrder(int n, vector<vector<int>>& prereqs) {
        vector<vector<int>> adjMat(n);
        for(auto req: prereqs) {
            adjMat[req[0]].push_back(req[1]);
        }
        for(int i=0;i<n;i++) {
            if(DFS(i, adjMat) == false)
                return {};
        }
        return out;
    }
    bool DFS(int n, vector<vector<int>>& adjMat) {
        if(cycle.find(n) != cycle.end())
            return false;
        if(seen.find(n) != seen.end())
            return true;;
        cycle.insert(n);
        bool flag = true;
        for(auto neig: adjMat[n]) {
            if(DFS(neig, adjMat) == false)
                return false;
        }
        cycle.erase(n);
        seen.insert(n);
        out.push_back(n);
        return flag;
    }
};