class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int l = prices.size();
        if(k <= 0 or l <= 1)
            return 0;
        else if(k >= l/2) {
            int profit = 0;
            for(int i=0;i<l-1;i++) {
                if(prices[i] < prices[i+1])
                    profit += prices[i+1] - prices[i];
            }
            return profit;
        }
        else {
            vector<int> buy(k, INT_MIN);
            vector<int> sel(k);
            for(int i=0;i<l;i++) {
                for(int j=0;j<k;j++) {
                    buy[j] = max(buy[j], (j==0)?(0-prices[i]):(sel[j-1]-prices[i]));
                    sel[j] = max(sel[j], buy[j]+prices[i]);
                }
            }
            return sel[k-1];
        }
    }
};