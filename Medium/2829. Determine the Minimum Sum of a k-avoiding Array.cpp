#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minimumSum(int n, int k) {
        int sum = 0;
        unordered_set<int> st;
        int i = 1;
        while(n) {
            if(st.find(i) == st.end()) {
                st.insert(i);
                st.insert(k-i);
                sum += i;
                n--;
            }
            i++;
        }
        return sum;
    }
};