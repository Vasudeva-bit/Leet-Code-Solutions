#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count = 0;
        int idx = 0;
        int i;
        for(i=1;i<=1000;i++) {
            if(arr[idx] != i) {
                count++;
                if(count == k)
                    break;
            }
            else {
                idx++;
                if(idx == arr.size())
                    break;
            }
        }
        count = k-count;
        while(count--) i++;
        return i;
    }
};