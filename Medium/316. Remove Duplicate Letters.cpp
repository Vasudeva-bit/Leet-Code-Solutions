#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, 0);
        for(int i=0;i<s.size();i++) {
            last[s[i]-'a'] = i;
        }
        vector<bool> seen(26, false);
        stack<char> st;
        for(int i=0;i<s.size();i++) {
            if(seen[s[i]-'a']) continue;
            while(!st.empty() and st.top() > s[i] and i < last[st.top()-'a']) {
                seen[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            seen[s[i]-'a'] = true;
        }
        string lexs = "";
        while(!st.empty()) {
            lexs += st.top();
            st.pop();
        }
        reverse(lexs.begin(), lexs.end());
        return lexs;
    }
};