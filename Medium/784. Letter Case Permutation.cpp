#include <bits/stdc++.h>
using namespace std;
// tags: C++, BFS, Vector
class Solution {
public:
    int count;
    vector<string> letterCasePermutation(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        vector<string> out;
        out.push_back(s);
        count = 1;
        for(int i=0;i<s.size();i++) {
            if(s[i] >= 48 and s[i] <= 57) 
                continue;
            Add(toupper(s[i]), i, out);
        }
        return out;
    }
    void Add(char ch, int pos, vector<string>& out) {
        for(int i=0;i<count;i++) {
            string s = out[i];
            s[pos] = ch;
            out.push_back(s);
        }
        count += count;
    }
};