class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        bool flag = false;
        for(int i=0;i<r;i++) {
            flag = flag or binary_search(matrix[i].begin(), matrix[i].end(), target);
        }
        return flag;
    }
};