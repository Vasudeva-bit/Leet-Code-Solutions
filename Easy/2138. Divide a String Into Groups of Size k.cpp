class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> out;
        for(int i=0;i<s.size();i = i+k) {
            string tmp = "";
            for(int j=i;j<i+k;j++) {
                if(j >= s.size())
                    tmp += fill;
                else
                    tmp += s[j];
            }
            out.push_back(tmp);
        }
        return out;
    }
};