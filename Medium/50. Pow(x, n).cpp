#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double out = 1;
        if(n < 0) {
            x = 1/x;
            n = abs(n);
        }
        while(n > 0) {
            if(n & 1) out *= x;
            x *= x;
            n = n>>1;
        }
        return out;
    }
};