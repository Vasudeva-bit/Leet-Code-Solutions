#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count = 0;
        for(auto hour: hours) {
            if(hour >= target)
                count++;
        }
        return count;
    }
};