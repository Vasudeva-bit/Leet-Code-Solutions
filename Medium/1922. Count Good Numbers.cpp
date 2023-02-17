class Solution {
public:
    long long mod = 1e9+7;
    long long power(long long b, long long p) {
        if(p == 0)
            return 1;
        if(p == 1)
            return b;
        if(p%2) {
            long long partialPowr = power(b, p/2);
            return ((b%mod)*(partialPowr*partialPowr))%mod;
        }
        else {
            long long partialPowr = power(b, p/2);
            return (partialPowr*partialPowr)%mod;
        }
    }
    int countGoodNumbers(long long n) {
        return ((power(5,(n+1)/2))%mod * (power(4,n/2))%mod)%mod;
    }
};