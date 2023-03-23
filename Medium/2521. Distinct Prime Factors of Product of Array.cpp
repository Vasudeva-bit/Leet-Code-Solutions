#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int> primes;
        vector<bool> isPrime(1001, true);
        for(int i=2;i<=1001;i++) {
            if(isPrime[i]) {
                primes.push_back(i);
                int j=i*i;
                while(j <= 1001) {
                    isPrime[j] = false;
                    j += i;
                }
            }
        }
        unordered_set<int> uset;
        for(int i=0;i<nums.size();i++) {
            int j=0;
            while(nums[i] > 1 and j != primes.size()) {
                if(nums[i]%primes[j] == 0) {
                    uset.insert(j);
                    while(nums[i]%primes[j] == 0) {
                        nums[i] /= primes[j];
                    }
                }
                j++;
            }
        }
        return uset.size();
    }
};