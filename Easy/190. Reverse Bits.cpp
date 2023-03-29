#include <bits/stdc++.h>
using namespace std;
// tags: C++, Bit Manipulation
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t out = 0;
        for(int i=0;i<32;i++) {
            int val = n&(1<<i);
            if(val) out = out*2+1;
            else out*=2;
        }
        return out;
    }
};