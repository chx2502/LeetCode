//
//  main.cpp
//  LeetCode_803_打砖块
//
//  Created by 成鑫 on 2019/1/10.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    const int MAX = 200;
    bool isFall(int row, int column, vector<vector<int>>& grid) {
        if (row == 0) {
            return false;
        }
        int left = column - 1;
        int right = column + 1;
        int up = row - 1;
        int down = row + 1;
        int connect = 0;
        if (0 < row < MAX-1) {
            if (0 < column < MAX-1) {
                connect = grid[row][left] + grid[row][right] + grid[up][column] + grid[down][column];
            } else {
                
            }
            
        } else {
            
        }
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j <= grid[i].size(); ++j) {
                <#statements#>
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
