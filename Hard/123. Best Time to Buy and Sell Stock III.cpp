class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        if(l < 2)
            return 0;
        else {
            vector<int> buy(2, INT_MIN);
            vector<int> sel(2);
            for(int i=0;i<l;i++) {
                for(int j=0;j<2;j++) {
                    buy[j] = max(buy[j], (j==0)?(0-prices[i]):(sel[j-1]-prices[i]));
                    sel[j] = max(sel[j], buy[j]+prices[i]);
                }
            }
            return sel[1];
        }
    }
};