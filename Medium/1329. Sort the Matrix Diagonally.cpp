class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // row 0
        int m = mat.size();
        int n = mat[0].size();
        for(int c=0;c<n;c++) {
            custom_sort(mat, 0, c, m, n);
        }
        // col = 0
        for(int r=1;r<m;r++) {
            custom_sort(mat, r, 0, m, n);
        }
        return mat;
    }
    void custom_sort(vector<vector<int>>& mat, int row, int col, int m, int n) {
        int r = row;
        int c = col;
        vector<int> values;
        while(r < m and c < n) {
            values.push_back(mat[r][c]);
            r++;
            c++;
        }
        sort(values.begin(), values.end(), greater<int>());
        r = row;
        c = col;
        while(r < m and c < n) {
            mat[r][c] = values.back();
            values.pop_back();
            r++;
            c++;
        }
    }
};