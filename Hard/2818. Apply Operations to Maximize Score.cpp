#include <bits/stdc++.h>
using namespace std;

const int primes[65] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};
int memo[100001] {};
int mod = 1000000007;
class Solution {
public:
    long power(long long a, unsigned long long b, unsigned long long mod) {
        long out =  1;
        while(b > 0) {
            if(b&1) out = (out*a)%mod;
            a = (a*a)%mod;
            b /= 2;
        }
        return out;
    }
    int primeScore(int n) {
        if(memo[n]) return memo[n];
        int score = 0;
        int val = n;
        for(int i=0;i<65 and primes[i]<=n;i++) {
            if(val%primes[i] == 0) score++;
            while(val%primes[i] == 0) {
                val /= primes[i];
            }
        }
        return memo[n] = score+(val>1);
    }
    int maximumScore(vector<int>& n, int k) {
        long long out = 1;
        int len = n.size();
        vector<int> id(len), l(len), r(len), score_l(8, -1), score_r(8, len);
        for(int i=0;i<len;i++) {
            int score = primeScore(n[i]);
            l[i] = *max_element(begin(score_l)+score, end(score_l));
            score_l[score] = i;
        }
        for(int i=len-1;i>=0;i--) {
            int score = primeScore(n[i]);
            r[i] = *min_element(begin(score_r)+score+1, end(score_r));
            score_r[score] = i;
        }
        auto compare = [&](int i, int j) {return n[i] < n[j];};
        iota(begin(id), end(id), 0);
        make_heap(begin(id), end(id), compare);
        while(!id.empty() and k>0) {
            int i = id.front();
            pop_heap(begin(id), end(id), compare);
            id.pop_back();
            long long take = min(k, (i-l[i])*(r[i]-i));
            out = (out*power(n[i], take, mod))%mod;
            k -= take;
        }
        return out;
    }
};