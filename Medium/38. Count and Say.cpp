class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        if(n == 2)
            return "11";
        string s = "11";
        for(int i=3;i<=n;i++) {
            s = s + "&";
            string t = "";
            int c = 1;
            for(int j=1;j<s.length();j++) {
                if(s[j] == s[j-1])
                    c++;
                else{
                    t = t + to_string(c);
                    c = 1;
                    t = t + s[j-1];
                }
            }
            s = t;
        }
        return s;
    }
};