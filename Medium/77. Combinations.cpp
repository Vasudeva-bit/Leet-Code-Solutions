#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void helper(vector<int> &out, int i, int n, int k) {
        if(out.size() == k) {
            if(find(result.begin(), result.end(), out) == result.end())
                result.push_back(out);
        }
        if(i > n)
            return;
        helper(out, i+1, n, k);
        out.push_back(i);
        helper(out, i+1, n, k);
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> out;
        helper(out, 1, n, k);
        return result;
    }
};