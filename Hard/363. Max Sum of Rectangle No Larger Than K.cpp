class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        int result = INT_MIN;
        for(int i=0;i<col;i++) {
            vector<int> sum(row);
            for(int j=i;j<col;j++) {
                for(int r=0;r<row;r++) {
                    sum[r] += matrix[r][j];
                }
                int tem_sum = 0;
                set<int> st = {0};
                for(auto val:sum) {
                    tem_sum += val;
                    auto it = st.lower_bound(tem_sum - k);
                    if(it != end(st)) {
                        result = max(result, tem_sum - *it);
                    }
                    st.insert(tem_sum);
                }
            }
        }
        return result;
    }
};