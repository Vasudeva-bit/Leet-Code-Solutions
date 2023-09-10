#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int sum = 0;
        int cnt = 0;
        for(int i=low;i<=high;i++) {
            string s = to_string(i);
            int len = s.size();
            if(len%2) continue;
            for(int j=0;j<len/2;j++) {
                sum += s[j]-'0';
            }
            for(int j=len/2;j<len;j++) {
                sum -= s[j]-'0';
            }
            if(sum == 0) cnt++;
            sum = 0;
        }
        return cnt;
    }
};