#include <bits/stdc++.h>
using namespace std;
#define ll long long
int power(long long x, long long y, int mod)
{
    unsigned ll out = 1;
    x %= mod;
    while(y > 0) {
        if(y & 1) out = (out*x)%mod;
        y >>= 1;
        x = (x*x)%mod;
    }
    return out;
}
class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> primes = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23, 29};
    unordered_map<int, int> primeMap;
    unordered_map<int, int> umap;
    int validMask(int mask, int n) {
        for(auto prime: primes) {
            if(n%prime == 0) {
                if(mask&(1<<primeMap[prime])) return 0;
                n /= prime;
                if(n%prime == 0) return 0;
                mask |= 1<<primeMap[prime];
            }
        }
        return mask;
    }
    int recurse(int idx, vector<int>& nums, int mask) {
        if(idx == nums.size())
            return mask != 0;
        int out = recurse(idx+1, nums, mask);
        int newMask = validMask(mask, nums[idx]);
        if(newMask != 0)
            out = (out+(1ll*umap[nums[idx]]*recurse(idx+1, nums, newMask))%mod)%mod;
        return out;
    }
    int squareFreeSubsets(vector<int>& nums) {
        for(int i=0;i<10;i++) {
            primeMap[primes[i]] = i+1;
        }
        for(int val: nums) {
            umap[val]++;
        }
        unordered_set<int> uset(nums.begin(), nums.end());
        nums.clear(); 
        for(int val: uset) {
            if(val == 1)
                continue;
            nums.push_back(val);
        }
        int out =recurse(0,nums,0)%mod;       
        int ones =(power(2,umap[1], mod)-1+mod)%mod;
        out =(out+1ll*out*ones%mod+ones)%mod;    
        return out;
    }
};
// Please consider upvoting if the solution helped! Thank you :)
// Credits: https://leetcode.com/i_pranav/