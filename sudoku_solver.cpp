#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    // first done on leetcode, now running in VS Code
    // so code looks a bit leetcode style

    // checking whether we can place digit here or not
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {

        // checking same row
        for(int i = 0; i < 9; i++){
            if(board[row][i] == dig)
                return false;
        }

        // checking same column
        for(int i = 0; i < 9; i++){
            if(board[i][col] == dig)
                return false;
        }

        // 3x3 box check (lecture 46 apna college, shraddha mam)
        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;

        for(int i = sr; i < sr + 3; i++){
            for(int j = sc; j < sc + 3; j++){
                if(board[i][j] == dig)
                    return false;
            }
        }

        return true;
    }

    // backtracking starts from here (LeetCode 37)
    bool solve(vector<vector<char>>& board, int row, int col){

        // if last row is crossed, sudoku is solved
        if(row == 9)
            return true;

        int nextRow = row;
        int nextCol = col + 1;

        if(nextCol == 9){
            nextRow = row + 1;
            nextCol = 0;
        }

        // if already filled, move forward
        if(board[row][col] != '.')
            return solve(board, nextRow, nextCol);

        // trying digits from 1 to 9
        for(char dig = '1'; dig <= '9'; dig++){
            if(isSafe(board, row, col, dig)){
                board[row][col] = dig;

                if(solve(board, nextRow, nextCol))
                    return true;

                // wrong choice, undo it (backtrack)
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};

int main() {

    vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter values (use . for empty cells):\n";

    // for input
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
        }
    }

    Solution solver; // needed because Solution class is used (OOPS)
    solver.solveSudoku(board);

    // printing solved sudoku
    cout<<"output is: \n";
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0; }
