// Dynamic Programming Approach:-
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=triangle.size()-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};




// Recursive Approach:-
class Solution {
public:
    int result = 0;
    int helper(vector<vector<int>>& triangle, int row, int idx){
        if(row >= triangle.size()){
            return 0;
        }
        
        return triangle[row][idx]+min(helper(triangle, row+1, idx), helper(triangle, row+1, idx+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return helper(triangle, 0, 0);
    }
};