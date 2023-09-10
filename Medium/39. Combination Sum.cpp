#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    set<vector<int>> out;
    void backtrack(int i, int sum, int target, vector<int>& cand, vector<int> comb) {
        if(sum == target) {
            out.insert(comb);
        }
        if(i >= cand.size() or sum > target) return;
        backtrack(i+1, sum, target, cand, comb);
        comb.push_back(cand[i]);
        sum += cand[i];
        backtrack(i, sum, target, cand, comb);
        backtrack(i+1, sum, target, cand, comb);
        comb.pop_back();
        sum -= cand[i];
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        backtrack(0, 0, target, candidates, comb);
        vector<vector<int>> result(begin(out), end(out));
        return result;
    }
};