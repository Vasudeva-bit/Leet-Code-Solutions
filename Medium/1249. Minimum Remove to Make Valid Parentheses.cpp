class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')') {
                if(st.size() > 0) {
                    st.pop();
                }
                else {
                    s.erase(s.begin() + i);
                    i--;
                }
            }
        }
        while(!st.empty()) {
            s.erase(s.begin() + st.top());
            st.pop();
        }
        return s;
    }
};