#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long exor = 0;
        for(int val: nums) 
            exor ^= val;
        vector<int> out = {0, 0};
        exor &= -exor;
        for(int val: nums) {
            if(exor&val)
                out[0] ^= val;
            else
                out[1] ^= val;
        }
        return out;
    }
};