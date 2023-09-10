#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n = prices.size();
        vector<int> finprices;
        st.push(prices[n-1]);
        finprices.push_back(st.top());
        for(int i=n-2;i>=0;i--) {
            while(!st.empty() and prices[i] < st.top()) st.pop();
            if(st.empty()) finprices.push_back(prices[i]);
            else finprices.push_back(prices[i]-st.top());
            st.push(prices[i]);
        }
        reverse(begin(finprices), end(finprices));
        return finprices;
    }
};