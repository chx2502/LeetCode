//
//  main.cpp
//  LeetCode_79
//
//  Created by chx on 2020/7/17.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<bool>> used;
    vector<vector<int>> next(int row, int col) {
        return {
            {row-1, col},
            {row+1, col},
            {row, col-1},
            {row, col+1}
        };
    }
    bool backtracking(int curr, vector<vector<char>>& board, string& word, int length, int row, int col, int m, int n) {
        if (curr == length) return true;
        if (row < 0 || row >= m || col < 0 || col >= n) return false;
        if (used[row][col]) return false;
        if (word[curr] != board[row][col]) return false;
        
        used[row][col] = true;
        vector<vector<int>> neighbor = next(row, col);
        for (auto item : neighbor) {
            if (backtracking(curr+1, board, word, length, item[0], item[1], m, n)) {
                used[row][col] = false;
                return true;
            }
        }
        used[row][col] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int length = (int)word.length();
        if (length == 0) return true;
        int m = (int)board.size();
        if (m == 0) return false;
        int n = (int)board[0].size();
        if (n == 0) return false;
        
        used.assign(m, vector<bool>(n, false));
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (backtracking(0, board, word, length, row, col, m, n)) return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Solution s;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    bool result = s.exist(board, word);
    return 0;
}
