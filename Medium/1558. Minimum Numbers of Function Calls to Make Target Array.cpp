#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseModify(vector<int>& nums, int& out) {
        bool flag = false;
        for(auto& val: nums) {
            if(val%2 == 1) {
                val -= 1;
                out++;
            }
            if(val != 0) {
                val /= 2;
                flag = true;
            }
        }
        if(flag) 
            out++;
        else
            return;
        reverseModify(nums, out);
        return;
    }
    int minOperations(vector<int>& nums) {
        int out = 0;
        reverseModify(nums, out);
        return out;
    }
};