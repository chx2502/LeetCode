//
//  main.cpp
//  LeetCode_529
//
//  Created by chx on 2020/8/20.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> around = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 1},
        {1, -1}, {1, 0}, {1, 1},
    };
    int count(vector<vector<char>>& board, int row, int col, int m, int n) {
        int result = 0;
        for (auto next : around) {
            int next_r = row + next.first;
            int next_c = col + next.second;
            if (next_r < 0 || next_c < 0 || next_r >= m || next_c >= n) continue;
            if (board[next_r][next_c] == 'M') result += 1;
        }
        return result;
    }
    
    void actionB(vector<vector<char>>& board, int row, int col, int m, int n) {
        board[row][col] = 'B';
        for (auto next : around) {
            int next_r = row + next.first;
            int next_c = col + next.second;
            if (next_r < 0 || next_c < 0 || next_r >= m || next_c >= n) continue;
            if (board[next_r][next_c] == 'E') {
                clickButton(board, next_r, next_c, m, n);
            }
        }
        return;
    }
    
    void clickButton(vector<vector<char>>& board, int row, int col, int m, int n) {
        if (board[row][col] == 'M') {
            board[row][col] = 'X';
            return;
        } else {
            int M_count = count(board, row, col, m, n);
            if(M_count == 0) actionB(board, row, col, m, n);
            else board[row][col] = '0' + M_count;
        }
        return;
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = (int)board.size();
        if (m == 0) return board;
        int n = (int)board[0].size();
        if (n == 0) return board;
        
        int row = click[0];
        int col = click[1];
        clickButton(board, row, col, m, n);
        return board;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
