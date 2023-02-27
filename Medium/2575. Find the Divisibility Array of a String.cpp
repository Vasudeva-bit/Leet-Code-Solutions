#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long n = 0;
        vector<int> out(word.size(), 0);
        for(int i=0;i<word.size();i++) {
            n = n*10 + word[i]-'0';
            if(n % m == 0) {
                out[i] = 1;
            }
            n %= m;
        }
        return out;
    }
};