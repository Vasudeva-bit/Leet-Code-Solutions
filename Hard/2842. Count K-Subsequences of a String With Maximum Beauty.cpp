#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    int mPow(int n, int p) {
        long res = 1, pow = n;
        while (p > 0) {
            if (p % 2 == 1) {
                res *= pow;
                res %= mod;
            }
            pow *= pow;
            pow %= mod;
            p >>= 1;
        }
        return (int)res;
    }
    
    int mInv(int n) {
        return mPow(n, mod - 2);
    }
    
    int ncr(int n, int k) {
        long res = 1;
        for (int i = 1; i <= n; i++) {
            res *= i;
            res %= mod;
        }
        for (int i = 1; i <= k; i++) {
            res *= mInv(i);
            res %= mod;
        }
        for (int i = 1; i <= n - k; i++) {
            res *= mInv(i);
            res %= mod;
        }
        return (int)res;
    }
    
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        if(k > 26) return 0;
        vector<int> freq(26, 0);
        for(char ch: s) {
            freq[ch-'a']++;
        }
        sort(begin(freq), end(freq));
        int req=0, tot=0;
        long cnt = 1;
        for(int i=25;i>=25-k+1;i--) {
            cnt *= freq[i];
            cnt %= mod;
            if(freq[i] == freq[25-k+1]) req++;
        }
        for(int i: freq) {
            if(i == freq[25-k+1]) tot++;
        }
        cnt *= ncr(tot, req);
        cnt %= mod;
        return (int)cnt;
    }
};