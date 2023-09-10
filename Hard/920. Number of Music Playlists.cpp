#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007
class Solution {
public:
    int dp[101][101];
    int N, L, K;
    ll solve(int n, int u) {
        if(n == L)
            return u == N;
        if(dp[n][u] != -1)
            return dp[n][u];
        ll ans = 0;
        ans = ((max(0, u - K))*solve(n+1, u)) % mod;
        ans += ((N-u)*solve(n+1, u+1)%mod) % mod;
        ans %= mod;
        return dp[n][u] = ans;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        N = n;
        L = goal;
        K = k;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};