#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
//    void search(int curr, int n, vector<int>& placed, vector<vector<int>>& result) {
//        if (curr == n) {
//            result.push_back(vector<int>(placed));
//            return;
//        }
//
//        for (int col = 0; col < n; ++col) {
//            bool flag = true;
//            placed[curr] = col;
//            for (int row = 0; row < curr; ++row) {
//                if (
//                        placed[row] == placed[curr] ||
//                        row - placed[row]== curr - placed[curr] ||
//                        row + placed[row] == curr + placed[curr]
//                        ) {
//                    flag = false;
//                    break;
//                }
//            }
//            if (flag) search(curr+1, n, result);
//        }
//    }
    vector<vector<bool>> visited;
    void search2(int curr, int n, vector<int>& placed, vector<vector<int>>& result) {
        if (curr == n) {
            result.push_back(vector<int>(placed));
            return;
        }
        for (int col = 0; col < n; ++col) {
            // 注意 visited[主对角线] 的越界访问
            if (!visited[0][col] && !visited[1][col-curr+n] && !visited[2][col+curr]) {
                placed[curr] = col;
                visited[0][col] = visited[1][col-curr+n] = visited[2][col+curr] = true;
                search2(curr+1, n, placed, result);
                visited[0][col] = visited[1][col-curr+n] = visited[2][col+curr] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> placed = vector<int>(n, -1);
        visited = vector<vector<bool>>(n, vector<bool>(n, false));
        vector<vector<string>> chessboards;
        vector<vector<int>> result;
//        search(0, n, placed, result);
        search2(0, n, placed,result);
        for (auto &solve : result) {
            string temp(n, '.');
            vector<string> chessboard(n, temp);
            for (int i = 0; i < n; ++i) {
                chessboard[i][solve[i]] = 'Q';
            }
            chessboards.push_back(chessboard);
        }
        return chessboards;
    }
};

int main() {
    Solution s;
    vector<vector<string>> result = s.solveNQueens(4);
    return 0;
}
