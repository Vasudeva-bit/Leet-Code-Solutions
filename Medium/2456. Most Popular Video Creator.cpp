class Solution {
public:
    bool static comp(pair<string,int> a, pair<string,int> b) {
        return a.second > b.second;
    }
    bool static cmpstr(vector<string> a, vector<string> b) {
        string one = a[0];
        string two = b[0];
        return (one.compare(two) <= 0);
    }
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, int> mapHi;
        unordered_map<string, long long> mapPo;
        unordered_map<string, string> ViId;
        int n = creators.size();
        for(auto creator:creators) {
            mapHi[creator] = -1;
        }
        for(int i=0;i<n;i++) {
            mapPo[creators[i]] += views[i];
            if(mapHi[creators[i]] < views[i]) {
                mapHi[creators[i]] = views[i];
                ViId[creators[i]] = ids[i];
            }
            else if(mapHi[creators[i]] == views[i]) {
                ViId[creators[i]] = min(ViId[creators[i]], ids[i]);
            }
        }
        vector<vector<string>> out;
        priority_queue<pair<int, string>> pq;
        for(auto it:mapPo) {
            pq.push({it.second, it.first});
        }
        int popular = pq.top().first;
        while(!pq.empty() and pq.top().first == popular) {
            vector<string> str;
            string s = pq.top().second;
            str.push_back(s);
            s = ViId[s];
            str.push_back(s);
            out.push_back(str);
            pq.pop();
        }
        reverse(out.begin(), out.end());
        return out;
    }
};