//
//  main.cpp
//  LeetCode_463
//
//  Created by chx on 2020/7/1.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getBankLength(int row, int col, vector<vector<int>>& grid) {
        return 4 - grid[row][col-1] - grid[row-1][col] - grid[row][col+1] - grid[row+1][col];
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        if (m == 0) return 0;
        int n = (int)grid[0].size();
        if (n == 0) return 0;
        
        grid.insert(grid.begin(), vector<int>(n, 0));
        grid.push_back(vector<int>(n, 0));
        for (auto &array : grid) {
            array.insert(array.begin(), 0);
            array.push_back(0);
        }
        
        int result = 0;
        for (int row = 1; row <= m; ++row) {
            for (int col = 1; col <=n ; ++col) {
                if (grid[row][col]) result += getBankLength(row, col, grid);
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
