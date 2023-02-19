#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> out;
    void recurSolve(int r, int c, map<pair<int, int>, map<int, int>>& mp, vector<map<int, int>>& row, vector<map<int, int>>& col, vector<vector<char>>& a) {
        if(r == 9) {
            out = a;
            return;
        }
        if(c == 9) {
            recurSolve(r+1, 0, mp, row, col, a);
            return;
        }
        if(a[r][c] != '.') {
            recurSolve(r, c+1, mp, row, col, a);
            return;
        }
        for(int val=1;val<=9;val++) {
            if(!mp[{r/3,c/3}][val] and !row[r][val] and !col[c][val]) {
                mp[{r/3,c/3}][val] = 1;
                row[r][val] = 1;
                col[c][val] = 1;
                a[r][c] = val+'0';
                recurSolve(r, c+1, mp, row, col, a);
                mp[{r/3,c/3}][val] = 0;
                row[r][val] = 0;
                col[c][val] = 0;
                a[r][c] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        int r = 9;
        int c = 9;
        map<pair<int, int>, map<int, int>> mp;
        vector<map<int, int>> row(r);
        vector<map<int, int>> col(c);
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(board[i][j] != '.') {
                    int val = board[i][j]-'0';
                    mp[{i/3, j/3}][val] = 1;
                    row[i][val] = 1;
                    col[j][val] = 1;
                }
            }
        }
        recurSolve(0, 0, mp, row, col, board);
        board = out;
    }
};