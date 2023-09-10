#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string convertToTitle(int col) {
        string out = "";
        while(col > 0) {
            out = char((col-1)%26+'A')+out;
            col = (col-1)/26;

        }
        return out;
    }
};