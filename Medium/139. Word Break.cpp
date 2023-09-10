#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<pair<string, bool>> dp;
    bool helper(string &s, vector<string>& wordDict) {
        if(dp.find({s, false}) != dp.end()) {
            return false;
        }
        if(dp.find({s, true}) != dp.end()) {
            return true;
        }
        string srch = "";
        bool flag = false;
        for(auto ch: s) {
            srch += ch;
            if(find(wordDict.begin(), wordDict.end(), srch) != wordDict.end()) {
                string remS = s.substr(srch.size());
                flag = flag or helper(remS, wordDict);
            }
        }
        dp.insert({s, flag});
        return flag;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.insert({"", true});
        return helper(s, wordDict);
    }
};