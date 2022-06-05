class Solution {
public:
    vector<vector<string>> result;
    set<int> cols;
    set<int> pos;
    set<int> neg;
    void backtrack(int row){
        if(row == grid){
            string cur;
            vector<string> tem;
            for(auto s:board){
                cur = "";
                for(auto ch : s){
                    cur += ch;
                }
                tem.push_back(cur);
            }
            result.push_back(tem);
        }
        for(int col=0;col<grid;col++){
            if(cols.find(col) != cols.end() ||
               pos.find(row+col) != pos.end() ||
               neg.find(row-col) != neg.end())
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
    int grid;
    vector<vector<string>> board;
    vector<vector<string>> solveNQueens(int n) {
        grid = n;
        board = vector<vector<string>>(n, vector<string>(n,"."));
        backtrack(0);
        return result;
    }
};