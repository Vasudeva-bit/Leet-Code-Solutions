class Solution {
public:
    string convert(string s, int numRows) {
        int nxt = 0;
        vector<string> sArr(numRows, "");
        while(nxt < s.size()) {
            int dir = 0;
            if(dir == 0) {
                int row = 0;
                while(row < numRows and nxt < s.size()) {
                    sArr[row++] += s[nxt++];
                }
                dir = 1;
            }
            if(dir == 1) {
                int row = numRows-2;
                while(row > 0 and nxt < s.size()) {
                    sArr[row--] += s[nxt++];
                }
            }
        }
        string out = "";
        for(auto str: sArr) {
            out += str;
        }
        return out;
    }
};