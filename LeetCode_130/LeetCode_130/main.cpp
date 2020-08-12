//
//  main.cpp
//  LeetCode_130
//
//  Created by chx on 2020/8/11.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> near = {
//        {-1, 0},
//        {0, -1},
        {1, 0},
        {0, 1},
    };
    queue<pair<int, int>> Q;
    void bfs(vector<vector<char>>& board, int row, int col) {
        int m = (int)board.size();
        int n = (int)board[0].size();
        
        Q.push(pair<int, int>(row, col));
        while (!Q.empty()) {
            pair<int, int> curr = Q.front();
            Q.pop();
            board[curr.first][curr.second] = '-';
            for (auto &array : near) {
                int next_r = curr.first + array[0];
                int next_c = curr.second + array[1];
                if (next_r < 0 || next_r >= m || next_c < 0 || next_c >= n || board[next_r][next_c] != 'O')
                    continue;
                Q.push(pair<int, int>(next_r, next_c));
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m = (int)board.size();
        if (m == 0) return;
        int n = (int)board[0].size();
        if (n == 0) return;
        
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                Q.emplace(i, 0);
            if (board[i][n-1] == 'O')
                Q.emplace(i, n-1);
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O')
                Q.emplace(0, i);
            if (board[m-1][i] == 'O')
                Q.emplace(m-1, i);
        }
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == 'O') board[row][col] = 'X';
                else if (board[row][col] == '-') board[row][col] = 'O';
            }
        }
    }
};

void printBoard(vector<vector<char>>& board) {
    for (auto &array : board) {
        for (auto &c : array)
            cout << c << " ";
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<string>> board = {
        {"O","X","O","O","O","O","O","O","O"},
        {"O","O","O","X","O","O","O","O","X"},
        {"O","X","O","X","O","O","O","O","X"},
        {"O","O","O","O","X","O","O","O","O"},
        {"X","O","O","O","O","O","O","O","X"},
        {"X","X","O","O","X","O","X","O","X"},
        {"O","O","O","X","O","O","O","O","O"},
        {"O","O","O","X","O","O","O","O","O"},
        {"O","O","O","O","O","X","X","O","O"},
    };
//    printBoard(board);
//    cout << endl;
//    s.solve(board);
//    printBoard(board);
    return 0;
}
