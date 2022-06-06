class Solution {
public:
    set<int> pos;
    set<int> neg;
    set<int> cols;
    int grid;
    int c = 0;
    void backtrack(int row){
        if(row == grid){
            c++;
        }
        for(int col=0;col<grid;col++){
            if(find(pos.begin(), pos.end(), row+col) != pos.end() ||
               find(cols.begin(), cols.end(), col) != cols.end() ||
               find(neg.begin(), neg.end(), row-col) != neg.end())
                continue;
            cols.insert(col);
            pos.insert(row+col);
            neg.insert(row-col);
            board[row][col] = "Q";
            
            backtrack(row+1);
            
            cols.erase(col);
            pos.erase(row+col);
            neg.erase(row-col);
            board[row][col] = ".";
        }
    }
    vector<vector<string>> board;
    int totalNQueens(int n) {
        grid = n;
        board = vector<vector<string>> (n, vector<string>(n, "."));
        backtrack(0);
        return c;
    }
};