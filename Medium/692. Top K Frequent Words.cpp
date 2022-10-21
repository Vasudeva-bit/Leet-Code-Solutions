struct cmp {
    bool operator() (pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};



class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto word:words) {
            mp[word]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> q;
        for(auto pair:mp) {
            q.push({pair.second, pair.first});
        }
        vector<string> out;
        while(k--) {
            out.push_back(q.top().second);
            q.pop();
        }
        return out;
    }
};