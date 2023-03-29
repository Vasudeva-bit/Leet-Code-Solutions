#include <bits/stdc++.h>
using namespace std;
// tags: C++, Array
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        set<char> leters(letters.begin(), letters.end());
        for(char ch=target+1;ch<='z';ch++) {
            if(leters.find(ch) != leters.end())
                return ch;
        }
        return letters[0];
    }
};