#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0, r=0;
        for(auto ch: moves) {
            if(ch == 'L') l++;
            if(ch == 'R') r++;
        }
        int extra = moves.size()-(l+r);
        return abs(l-r)+extra;
    }
};