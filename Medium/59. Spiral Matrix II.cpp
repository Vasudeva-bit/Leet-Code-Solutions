class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> result(n, vector<int>(n, 0));
        int rowStart = 0;
        int rowEnd = n-1;
        int colStart = 0;
        int colEnd = n-1;
        int c = 1;
        while(rowStart <= rowEnd && colStart <= colEnd){
            // a loop for top row
            for(int i=colStart;i<=colEnd;i++){
                result[rowStart][i] = c++;
            }
            rowStart++;
            // a loop for right side
            for(int i=rowStart;i<=rowEnd;i++){
                result[i][colEnd] = c++;
            }
            colEnd--;
            if(rowStart <= rowEnd){
                // a loop for bottom
                for(int i=colEnd;i>=colStart;i--){
                    result[rowEnd][i] = c++;
                }
            }
            rowEnd--;
            if(colStart <= colEnd){
                // a loop for left side
                for(int i=rowEnd;i>=rowStart;i--){
                    result[i][colStart] = c++;
                }
            }
            colStart++;
        }
        return result;
    }
};
