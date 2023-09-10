#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_set<int> st;
        long long sum = 0;
        int t = 0;
        for(int i=1;t<n;i++) {
            if(st.find(i) == st.end()) {
                sum += i;
                if(i < target)
                    st.insert(target-i);
                t++;
            }
        }
        return sum;
    }
};