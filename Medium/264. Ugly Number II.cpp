#include <bits/stdc++.h>
using namespace std;
// tags: Dynamic Programming, Recursion, Memoization
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> memo(n+1);
        memo[1] = 1;
        int two=1, three=1, five=1;
        for(int i=2;i<=n;i++) {
            int mulTwo = 2*memo[two];
            int mulThree = 3*memo[three];
            int mulFive = 5*memo[five];
            memo[i] = min(mulTwo, min(mulThree, mulFive));
            if(mulTwo == memo[i]) two++;
            if(mulThree == memo[i]) three++;
            if(mulFive == memo[i]) five++;
        }
        return memo[n];
    }
};