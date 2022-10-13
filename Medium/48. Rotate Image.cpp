class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix.size()-1;
        while(l<r) {
            for(int i=0;i<r-l;i++) {
                int top = l;
                int bottom = r;
                // store the top left in a temp variable
                int temp = matrix[top][l+i];
                // store the bottom left in top left
                matrix[top][l+i] = matrix[bottom-i][l];
                // store the bottom right in bottom left
                matrix[bottom-i][l] = matrix[bottom][r-i];
                // store the top right in bottom right
                matrix[bottom][r-i] = matrix[top+i][r];
                // store the top left in top right
                matrix[top+i][r] = temp;
            }
            l++;
            r--;
        }
    }
};