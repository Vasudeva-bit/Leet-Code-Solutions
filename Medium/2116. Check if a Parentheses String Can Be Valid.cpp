class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2 != 0)
            return false;
        int tot = 0;
        int open = 0;
        int close = 0;
        for(int i=0;i<n;i++) {
            if(locked[i] == '0')
                tot++;
            else if(s[i] == ')')
                close++;
            else if(s[i] == '(')
                open++;
            if(tot + open < close)
                return false;
        }
        tot = 0;
        open = 0;
        close = 0;
        for(int i=n-1;i>=0;i--) {
            if(locked[i] == '0')
                tot++;
            else if(s[i] == ')')
                close++;
            else if(s[i] == '(')
                open++;
            if(tot + close < open)
                return false;
        }
        return true;
    }
};