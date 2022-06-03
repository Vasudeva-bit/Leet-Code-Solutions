class NumMatrix {
public:
    vector<vector<int>> expan;
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        expan = vector<vector<int>>(r+1, vector<int>(c+1,0));
        for(int i=0;i<r;i++){
            int tem = 0;
            for(int j=0;j<c;j++){
                tem += matrix[i][j];
                expan[i+1][j+1] = tem + expan[i][j+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return expan[row2+1][col2+1] - expan[row1][col2+1] - expan[row2+1][col1] + expan[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */