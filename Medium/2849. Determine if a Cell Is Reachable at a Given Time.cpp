#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int v = max(abs(sx-fx), abs(fy-sy));
        if(v == 0) return t!=1;
        if(t >= v) return true;
        else return false;
    }
};