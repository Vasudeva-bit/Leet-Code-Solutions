class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++) {
            if(s[i] != ']')
                st.push(s[i]);
            else {
                string substr = "";
                while(!st.empty() and st.top() != '[') {
                    substr = st.top() + substr;
                    st.pop();
                }
                st.pop();
                string num = "";
                while(!st.empty() and st.top() >= '0' and st.top() <= '9') {
                    num = st.top() + num;
                    st.pop();
                }
                int n = stoi(num);
                for(int i=0;i<n;i++) {
                    for(auto ch:substr) {
                        st.push(ch);
                    }
                }
            }
        }
        string out = "";
        while(!st.empty()) {
            out += st.top();
            st.pop();
        }
        reverse(out.begin(), out.end());
        return out;
    }
};