class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> result;
        for(int i=0;i<s.size();i++) {
            int x = i;
            int y = i;
            while(x >= 0 or y < s.size()) {
                if((x >= 0 and s[x] == c) or (y < s.size() and s[y] == c)) break;
                x--;
                y++;
            }
            result.push_back(min(abs(x-i), abs(y-i)));
        }
        return result;
    }
};