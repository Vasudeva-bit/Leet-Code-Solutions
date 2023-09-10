#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int i = 0;
        int j = 0;
        while(i < n) {
            if(str1[i] == str2[j] or (str1[i]-'a'+1)%26 == str2[j]-'a') {
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        if(j == m)
            return true;
        else
            return false;
    }
};