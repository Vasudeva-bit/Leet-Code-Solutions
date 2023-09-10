#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> ste, sto;
        for(int i=0;i<s1.size();i++) {
            if(i%2) {
                sto[s1[i]]++;
            }
            else {
                ste[s1[i]]++;
            }
        }
        for(int i=0;i<s2.size();i++) {
            if(i%2) {
                sto[s2[i]]--;
                if(sto[s2[i]] == 0) sto.erase(s2[i]);
            }
            else {
                ste[s2[i]]--;
                if(ste[s2[i]] == 0) ste.erase(s2[i]);
            }
        }
        if(sto.size() == 0 and ste.size() == 0) return true;
        else return false;
    }
};