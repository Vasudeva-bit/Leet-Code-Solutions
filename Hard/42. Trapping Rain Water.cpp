#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int trap(vector<int>& h) {
        int left = 0;
        int right = h.size()-1;
        int leftMax = h[left];
        int rightMax = h[right];
        int out = 0;
        while(left < right) {
            if(leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, h[left]);
                out += leftMax - h[left];
            }
            else {
                right--;
                rightMax = max(rightMax, h[right]);
                out += rightMax - h[right];
            }
        }
        return out;
    }
};