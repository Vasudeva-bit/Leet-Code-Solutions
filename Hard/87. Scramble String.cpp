#include <bits/stdc++.h>
using namespace std;
// tags: C++, Memoization, Hash Table
class Solution {
public:
    unordered_map<string, bool> umap;
    bool isScrambled(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        int n = s1.size();
        if(s1 == s2 or n == 0)
            return true;
        if(umap.find(s1+""+s2) != umap.end())
            return umap[s1+""+s2];
        bool flag = false;
        for(int i=1;i<n;i++) {
            // Swapped case
            if(isScrambled(s1.substr(0, i), s2.substr(n-i, i)) and isScrambled(s1.substr(i, n-i), s2.substr(0, n-i))){
                flag |= true;
                break;
            }
            else if(isScrambled(s1.substr(0, i),s2.substr(0, i)) and isScrambled(s1.substr(i, n-i),s2.substr(i, n-i))) {
                flag |= true;
                break;
            }
        }
        umap[s1+""+s2] = flag;
        return flag;
    }
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        return isScrambled(s1, s2);
    }
};
// Please consider upvoting, if the solution helped! Thank you :)
// Credits: DeepCodes (YouTube Channel)