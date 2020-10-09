//
//  main.cpp
//  LeetCode_37
//
//  Created by chx on 2020/9/16.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<bool>> row_map;
    vector<vector<bool>> col_map;
    vector<vector<bool>> square_map;
    
    pair<int, int> next_pos(int row, int col) {
        int next_row = row;
        int next_col = col;
        next_col = next_col + 1;
        if (next_col > 8) {
            next_col = 0;
            next_row += 1;
        }
        return {next_row, next_col};
    }
    
    void backTracking(vector<vector<char>>& board, int row, int col, bool& result) {
        if (row >= 9 || col >= 9) {
            result = true;
            return;
        }
        pair<int, int> next = next_pos(row, col);
        if (board[row][col] != '.') {
            backTracking(board, next.first, next.second, result);
            return;
        }
        int square = row/3 * 3 + col/3;
        for (int curr = 1; curr <= 9; curr++) {
            if (row_map[row][curr] || col_map[col][curr]|| square_map[square][curr]) continue;
            board[row][col] = '0' + curr;
            row_map[row][curr] = col_map[col][curr] = square_map[square][curr] = true;
            backTracking(board, next.first, next.second, result);
            if (result) break;
            else {
                board[row][col] = '.';
                row_map[row][curr] = col_map[col][curr] = square_map[square][curr] = false;
            }
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        row_map.assign(9, vector<bool>(10, false));
        col_map.assign(9, vector<bool>(10, false));
        square_map.assign(9, vector<bool>(10, false));
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.') {
                    int curr = board[row][col] - '0';
                    int square = row/3*3 + col/3;
                    row_map[row][curr] = col_map[col][curr] = square_map[square][curr] = true;
                }
            }
        }
        bool result = false;
        backTracking(board, 0, 0, result);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    s.solveSudoku(board);
    return 0;
}
