#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> mapper;  
    vector<string> out;
    void helper(int i, string &str, string &digits) {
        if(i == digits.size()) {
            out.push_back(str);
            return;
        }
        for(auto ch: mapper[int(digits[i]-'0')]) {
            str += ch;
            helper(i+1, str, digits);
            str = str.substr(0, str.size()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return out;
        mapper = vector<string>(10);
        string str = "";
        mapper[2] = "abc";
        mapper[3] = "def";
        mapper[4] = "ghi";
        mapper[5] = "jkl";
        mapper[6] = "mno";
        mapper[7] = "pqrs";
        mapper[8] = "tvu";
        mapper[9] = "wxyz";
        helper(0, str, digits);
        return out;
    }
};