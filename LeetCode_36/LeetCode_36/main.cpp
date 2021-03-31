//
//  main.cpp
//  LeetCode_36
//
//  Created by chx on 2021/3/3.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, unordered_map<int, bool>> rowMap;
    unordered_map<int, unordered_map<int, bool>> colMap;
    unordered_map<int, unordered_map<int, bool>> regionMap;
    vector<vector<int>> regions = {
        {0, 0}, {0, 3}, {0, 6},
        {3, 0}, {3, 3}, {3, 6},
        {6, 0}, {6, 3}, {6, 6}
    };
    int getRegionIndex(int row, int col) {
        return (row / 3) * 3 + col/3;
    }
public:
    /*
     核心思路：
     三个 map 分别存储各行、列、块的数字出现情况，每行、列、块用一个 map 来记录
     **/
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = (int)board.size();
        if (m == 0) return false;
        int n = (int)board[0].size();
        if (n == 0) return false;
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == '.') continue;
                int curr = board[row][col] - '0';
                if (rowMap[row].find(curr) == rowMap[row].end()) rowMap[row][curr] = true;
                else return false;
                if (colMap[col].find(curr) == colMap[col].end()) colMap[col][curr] = true;
                else return false;
                int region = getRegionIndex(row, col);
                if (regionMap[region].find(curr) == regionMap[region].end()) regionMap[region][curr] = true;
                else return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
