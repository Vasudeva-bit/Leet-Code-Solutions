#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string finalString(string s) {
        string out = "";
        for(auto ch: s) {
            if(ch == 'i') {
                reverse(out.begin(), out.end());
            }
            else
                out += ch;
        }
        return out;
    }
};