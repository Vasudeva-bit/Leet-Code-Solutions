class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> freq;
        if(s.size() < 10)
            return {};
        for(int i=0;i<s.size()-9;i++) {
            freq[s.substr(i, 10)]++;
        }
        vector<string> result;
        for(auto pair:freq) {
            if(pair.second > 1)
                result.push_back(pair.first);
        }
        return result;
    }
};