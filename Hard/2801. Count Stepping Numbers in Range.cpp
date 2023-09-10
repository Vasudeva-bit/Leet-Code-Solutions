#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1000000007;
class Solution {
public:
    ll helper(ll pos, ll tight, ll isZero, ll prevDigit, string &s) {
        if(pos == (ll)s.size()) {
            if(isZero) return 0;
            return 1;
        }
        if(dp[pos][tight][isZero][prevDigit+1] != -1)
            return dp[pos][tight][isZero][prevDigit+1];
        ll out = 0;
        ll limit;
        if(tight) limit = (s[pos] - '0');
        else limit = 9;
        for(ll curDigit=0; curDigit<=limit; curDigit++) {
            ll newTight = tight;
            if(tight and curDigit < limit) newTight = 0;
            ll newIsZero = isZero;
            if(isZero and curDigit > 0) newIsZero = 0;
            if(isZero) {
                out += helper(pos+1, newTight, newIsZero, curDigit, s);
            }
            else {
                if(abs(curDigit-prevDigit) == 1) {
                    out += helper(pos+1, newTight, newIsZero, curDigit, s);
                    out %= mod;
                }
            }
        }
        dp[pos][tight][isZero][prevDigit+1] = out;
        return out;
    }
    int dp[101][2][2][11];
    int countSteppingNumbers(string low, string high) {
        memset(dp, -1, sizeof(dp));
        ll l = helper(0, 1, 1, -1, low);
        memset(dp, -1, sizeof(dp));
        ll r = helper(0, 1, 1, -1, high);
        ll  out = (((r-l)%mod)+mod)%mod;
        bool toAdd = true;
        for(ll i=1;i<(ll)low.size();i++) 
            if(abs(low[i]-low[i-1]) != 1) toAdd = false;
        if(toAdd) out++;
        out %= mod;
        return out; 
    }
};