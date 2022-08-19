class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> result(n);
        if(n == 1) return {{1}};
        result[0] = {1};
        result[1] = {1, 1};
        for(int i=2;i<n;i++) {
            result[i].resize(i+1);
            result[i][0] = 1;
            for(int j=1;j<i;j++) {
                result[i][j] = result[i-1][j-1] + result[i-1][j]; 
            }
            result[i][i] = 1;
        }
        return result;
    }
};