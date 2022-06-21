class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s(words.begin(), words.end());
        for(auto i:s){
            for(int j=1;j<i.size();j++){
                s.erase(i.substr(j));
            }
        }
        int result = 0;
        for(auto i:s)
            result += i.size()+1;
        return result;
    }
};