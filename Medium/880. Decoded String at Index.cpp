#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long i;
        long N = 0;
        for(i=0;N<k;i++) {
            if(isdigit(s[i])) N *= s[i]-'0';
            else N++;
        }
        while(i--) {
            if(isdigit(s[i])) {
                N /= s[i]-'0';
                k %= N;
            }
            else if(k%N-- == 0) 
                return string(1, s[i]);
        }
        return "kvd";
    }
};