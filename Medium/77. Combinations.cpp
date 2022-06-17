class Solution {
public:
    vector<vector<int>> result;
    vector<int> comb;
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1, comb);
        return result;
    }
    
    void backtrack(int n, int k, int start, vector<int> comb){
        if(comb.size() == k){
            result.push_back(comb);
            return;
        }
        for(int i=start;i<=n;i++){
            comb.push_back(i);
            backtrack(n, k, i+1, comb);
            comb.pop_back();
        }
    }
};