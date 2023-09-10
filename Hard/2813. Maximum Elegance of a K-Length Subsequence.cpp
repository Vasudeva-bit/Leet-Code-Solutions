#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(),items.end(),greater<vector<int>>());
        int n = items.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        long long elegance = 0;
        long long cats = 0;
        vector<bool> seen(n+1, false);
        for(int i=0;i<k;i++) {
            if(seen[items[i][1]]) {
                pq.push(items[i][0]);
            }
            else 
                cats++;
            seen[items[i][1]] = true;
            elegance += items[i][0];
        }
        elegance += cats*cats;
        if(pq.empty()) return elegance;
        long long out = elegance;
        for(int i=k;i<n;i++) {
            if(seen[items[i][1]] == false) {
                elegance += (long long)items[i][0]-pq.top();
                pq.pop();
                elegance += ((cats+1)*(cats+1) - cats*cats);
                out = max(out, elegance);
                if(pq.empty()) return out;
                cats++;
                seen[items[i][1]] = true;
            }
        }
        return out;
    }
};