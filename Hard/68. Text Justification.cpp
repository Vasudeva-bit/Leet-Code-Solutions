#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> out;
        vector<string> wrk;
        int curlen = 0;
        for(auto word: words) {
            if(word.size()+curlen+wrk.size() > maxWidth) {
                for(int i=0;i<maxWidth-curlen;i++) {
                    wrk[i%(wrk.size()-1?wrk.size()-1:1)] += " ";
                }
                out.push_back("");
                for(auto s: wrk) out.back() += s;
                wrk.clear();
                curlen = 0;
            }
            wrk.push_back(word);
            curlen += word.size();
        }
        string last = "";
        for(auto s: wrk) {
            last += s+" ";
        }
        last = last.substr(0, last.size()-1);
        while(last.size() < maxWidth) last += " ";
        out.push_back(last);
        return out;
    }
};