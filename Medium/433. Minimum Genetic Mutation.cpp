class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> visited;
        set<string> banc(bank.begin(), bank.end());
        queue<pair<string, int>> q;
        q.push({start, 0});
        visited.insert(start);
        if(banc.find(end) == banc.end())
            return -1;
        while(!q.empty()) {
            auto pair = q.front();
            q.pop();
            if(pair.first == end) 
                return pair.second;
            auto gene = pair.first;
            for(int i=0;i<8;i++) {
                for(auto ch:"ACGT") {
                    string novel = gene.substr(0, i) + ch + gene.substr(i+1);
                    if(visited.find(novel) == visited.end() and banc.find(novel) != banc.end()) {
                        q.push({novel, pair.second+1});
                        visited.insert(novel);
                    }
                }
            }
        }
        return -1;
    }
};