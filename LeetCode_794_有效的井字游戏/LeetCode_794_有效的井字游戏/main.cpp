//
//  main.cpp
//  LeetCode_794_有效的井字游戏
//
//  Created by chx on 2019/10/22.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool win(vector<string>& board, int row, int col, char winner) {
        for (int i = 0; i < row; i++) {
            if (board[i][0] == winner && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        }
        for (int i = 0; i < col; i++) {
            if (board[0][i] == winner && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
        }
        if (board[0][0] == winner && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return true;
        return false;
    }
    bool validTicTacToe(vector<string>& board) {
        int row = (int)board.size();
        int col = (int)board[0].size();
        int count = 0;
        map<char, int> char_map = {{'X', 0}, {'O', 0}};
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                char chess_piece = board[i][j];
                if (board[i][j] != ' ') {
                    count += 1;
                    if (count == 1 && char_map['O'] == 1) return false;
                    char_map[chess_piece] += 1;
                }
            }
        if (count == 0) return true;
        if (char_map['X'] < char_map['O']) return false;
        if (abs(char_map['X'] - char_map['O']) >= 2) return false;
        if (char_map['X'] == char_map['O']) {
            if (win(board, row, col, 'X')) return false;
        }
        if (win(board, row, col, 'X') && win(board, row, col, 'O')) return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> board = {"XXX", "   ", "OOO"};
    Solution s;
    bool result = s.validTicTacToe(board);
    cout << (int)'X' << ' ' << (int)'O';
    return 0;
}
