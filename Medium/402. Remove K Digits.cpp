#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char n: num) {
            while(!st.empty() and k and st.top() > n) {
                st.pop();
                k--;
            }
            if(!st.empty() or n != '0') st.push(n);
        }
        string out = "";
        while(!st.empty()) {
            out += st.top();
            st.pop();
        }
        reverse(begin(out), end(out));
        out = out.substr(0, max(0,(int)out.size()-k));
        if(out == "") return "0";
        else return out;
    }
};