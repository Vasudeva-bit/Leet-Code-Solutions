#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string merge(string a, string b) {
        string merge = a+b;
        for(int i=(b.size(), a.size())-1;i>=0;i--) {
            string ad = a.substr(a.size()-1-i);
            string bd = b.substr(0, i+1);
            if(ad.compare(bd) == 0) {
                merge = a + b.substr(i+1); 
                break;
            }
        }
        return merge;
    }
    string solve(string a, string b) {
        if(a.find(b) != string::npos)
            return a;
        if(b.find(a) != string::npos)
            return b;
        string merge1="", merge2="";
        merge1 = merge(a, b);
        merge2 = merge(b, a);
        if(merge1.size() < merge2.size())
            return merge1;
        else if(merge2.size() < merge1.size())
            return merge2;
        else
            return min(merge1, merge2);
    }
    static bool compare(string &a, string &b) {
        if (a.size() == b.size())
            return a < b;
        return a.size() < b.size();
    }
    string minimumString(string a, string b, string c) {
        string ab = solve(a, b);
        string bc = solve(b, c);
        string ac = solve(a, c);
        string out1 = solve(ab, c);
        string out2 = solve(bc, a);
        string out3 = solve(ac, b);

        vector<string> out;
        out.push_back(out1);
        out.push_back(out2);
        out.push_back(out3);
        sort(out.begin(), out.end(), compare);
        return out[0];
    }
};