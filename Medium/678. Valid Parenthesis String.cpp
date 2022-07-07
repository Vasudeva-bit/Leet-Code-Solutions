class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> star;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '(')
                open.push(i);
            else if(s[i] == '*')
                star.push(i);
            else if(s[i] == ')') {
                if(open.size() > 0)
                    open.pop();
                else if(star.size() > 0)
                    star.pop();
                else 
                    return false;
            }
        }
        while(!open.empty()) {
            if(star.empty())
                return false;
            else if(open.top() < star.top()) {
                open.pop();
                star.pop();
            }
            else 
                return false;
        }
        return true;
    }
};