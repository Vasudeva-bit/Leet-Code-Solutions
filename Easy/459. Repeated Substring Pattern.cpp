#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str = s+s;
        str = str.substr(1, str.size()-2);
        if(str.find(s) != string::npos)
            return true;
        return false;
    }
};