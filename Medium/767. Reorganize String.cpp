class Solution {
public:
    string reorganizeString(string s) {
        int n;
        if(s.size() == 1)
            return s;
        unordered_map<char, int> umap;
        for(auto ch:s) {
            umap[ch]++;
        }
        if(umap.size() == 1)
            return "";
        priority_queue<pair<int, char>> pq;
        for(auto it:umap) {
            pq.push({it.second, it.first});
        }
        string result = "";
        while(pq.top().first > 0) {
            pair<int, char> p1 = pq.top();
            pq.pop();
            result += p1.second;
            p1.first--;
            pair<int, char> p2 = pq.top();
            pq.pop();
            if(p2.first > 0) {
                result += p2.second;
                p2.first--;
            }
            pq.push(p1);
            pq.push(p2);
        }
        n = result.size();
        for(int i=1;i<n;i++) {
            if(result[i] == result[i-1])
                return "";
        }
        return result;
    }
};