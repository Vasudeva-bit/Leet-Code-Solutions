#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    set<string> st;
    map<pair<int, string>, int> dp;
    int search(string& s, int pos, string frm) {
        if(pos == s.size()) {
            if(st.find(frm) == st.end()) {
                return frm.size();
            }
            else {
                return 0;
            }
        }
        if(dp.find({pos, frm}) != dp.end()) return dp[{pos, frm}];
        int left1 = frm.size()+1+search(s, pos+1, "");
        string nfrm = frm;
        nfrm += s[pos];
        int left2 = search(s, pos+1, nfrm);
        int left3 = 51;
        if(st.find(nfrm) != st.end()) {
            left3 = search(s, pos+1, "");
        }
        return dp[{pos, frm}] = min(left1, min(left2, left3));
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        st = set<string>(begin(dictionary), end(dictionary));
        return search(s, 0, "");
    }
};