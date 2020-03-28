#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int search(vector<vector<char>>& board, int row, int col, int n) {
        int result = 0;
        for (int temp = row-1; temp >=0; --temp) {
            if (board[temp][col] == 'p') {
                result += 1;
                break;
            }
            if (board[temp][col] == 'B') break;
        }
        for (int temp = row+1; temp < n; ++temp) {
            if (board[temp][col] == 'p') {
                result += 1;
                break;
            }
            if (board[temp][col] == 'B') break;
        }
        for (int temp = col-1; temp >=0; --temp) {
            if (board[row][temp] == 'p') {
                result += 1;
                break;
            }
            if (board[row][temp] == 'B') break;
        }
        for (int temp = col+1; temp < n; ++temp) {
            if (board[row][temp] == 'p') {
                result += 1;
                break;
            }
            if (board[row][temp] == 'B') break;
        }
        return result;
    }

    int numRookCaptures(vector<vector<char>>& board) {
        int n = (int)board.size();
        if (n == 0) return 0;
        int result = 0;
        int row, col;
        row = col = 0;
        for (int i = 0; i < n; ++i) {
            int left = 0;
            int right = board[i].size()-1;
            bool flag = false;
            while (left < right) {
                if (board[i][left] == 'R') {
                    row = i;
                    col = left;
                    flag = true;
                }
                if (board[i][right] == 'R') {
                    row = i;
                    col = right;
                    flag = true;
                }
                if (flag) break;
                ++left;
                --right;
            }
            if (flag) break;
        }
        result = search(board, row, col, n);
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
