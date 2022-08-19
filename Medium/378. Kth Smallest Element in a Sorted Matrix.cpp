class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> tem(matrix.size()*matrix.size());
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix.size();j++) {
                tem[i*matrix.size()+j] = matrix[i][j];
            }
        }
        sort(tem.begin(), tem.end());
        return tem[k-1];
    }
};