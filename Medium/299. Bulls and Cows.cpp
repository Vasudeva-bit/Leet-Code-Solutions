#include <bits/stdc++.h>
using namespace std;
// tags: C++, Hash Table, String Manipulation
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bulls = 0, cows = 0;
        unordered_map<char, int> umap1, umap2;
        for(int i=0;i<n;i++) {
            if(secret[i] == guess[i])
                bulls++;
            else {
                umap1[secret[i]]++;
                umap2[guess[i]]++;
            }
        }
        for(int i=0;i<n;i++) {
            int cow = min(umap1[secret[i]], umap2[secret[i]]);
            umap1[secret[i]] -= cow;
            umap2[secret[i]] -= cow;
            cows += cow;
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
// Please consider upvoting, if the solution helped! Thank you :)
// By VasudevaK (V Deva K)