#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char sep) {
      vector<string> out;
      for(auto str: words) {
        string toAdd = "";
        for(auto ch: str) {
          if(ch == sep) {
            if(toAdd != "")
              out.push_back(toAdd);
            toAdd = "";
          }
          else {
            toAdd += ch;
          }
        }
        if(toAdd != "")
          out.push_back(toAdd);
      }
      return out;
    }
};