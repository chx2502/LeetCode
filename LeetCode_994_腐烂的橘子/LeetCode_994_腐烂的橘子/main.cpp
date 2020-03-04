//
//  main.cpp
//  LeetCode_994_腐烂的橘子
//
//  Created by chx on 2020/3/4.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     此解法很不优雅，心态爆炸，明天再改。
     **/
    void rot(int &orange) {
        if (orange == 1) {
            orange = 3;
        }
    }
    void helper(vector<vector<int>> &grid, int row, int col) {
        grid[row][col] = -1;
        rot(grid[row-1][col]);
        rot(grid[row+1][col]);
        rot(grid[row][col-1]);
        rot(grid[row][col+1]);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        if (m == 0) return 0;
        
        int count = 0;
        for (auto &array : grid)
            for (auto &orange : array)
                if (orange == 1) count++;
        
        vector<int> boundary(n, 0);
        grid.insert(grid.begin(), boundary);
        grid.push_back(boundary);
        for (auto &array : grid) {
            array.insert(array.begin(), 0);
            array.push_back(0);
        }
        
        int step = 0;
        while (count) {
            bool flag = false;
            step++;
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (grid[i][j] == 2)
                        helper(grid, i, j);
                }
            }
            for (int i = 1; i <= m; ++i)
                for (int j = 1; j <= n; ++j)
                    if (grid[i][j] == 3) {
                        grid[i][j] = 2;
                        count--;
                        flag = true;
                    }
            if (count == 0) return step;
            if (!flag) return -1;
        }
        return step;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> grid = {{2,1,0,2}};
    int result = s.orangesRotting(grid);
    return 0;
}
