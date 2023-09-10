#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string ac = "";
        for(auto &word: words) {
            ac += word[0];
        }
        if(ac == s) return true;
        else return false;
    }
};