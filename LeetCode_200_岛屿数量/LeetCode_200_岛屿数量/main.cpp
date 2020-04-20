//
//  main.cpp
//  LeetCode_200_岛屿数量
//
//  Created by chx on 2020/4/20.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    void dfs(int row, int col, int m, int n, vector<vector<char>>& grid) {
        if (row < 0 || col < 0 || row >= m || col >= n) return;
        if (grid[row][col] == '0') return;
        grid[row][col] = '0';
        dfs(row, col-1, m, n, grid);
        dfs(row-1, col, m, n, grid);
        dfs(row, col+1, m, n, grid);
        dfs(row+1, col, m, n, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int m = (int)grid.size();
        if (m == 0) return result;
        int n = (int)grid[0].size();
        if (n == 0) return result;
        
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == '1') {
                    dfs(row, col, m, n, grid);
                    result += 1;
                }
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
