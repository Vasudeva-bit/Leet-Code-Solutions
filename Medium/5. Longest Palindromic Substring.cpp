class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int resLen = 0;
        for(int i=0;i<s.size();i++){
            // for even palindromes
            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if((r-l+1) > resLen){
                    resLen = r-l+1;
                    res = s.substr(l, resLen);
                }
                r++;
                l--;
            }
            // for odd palindromes
            l = i;
            r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if((r-l+1) > resLen){
                    resLen = r-l+1;
                    res = s.substr(l, resLen);
                }
                r++;
                l--;
            }
        }
        return res;
    }
};