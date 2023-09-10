#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        double amt = (purchaseAmount*1.0)/10;
        double roundedAmount  = round(amt);
        return 100-((int)roundedAmount*10);
    }
};