//
//  main.cpp
//  LeetCode_1351_统计有序矩阵中的负数
//
//  Created by chx on 2020/3/10.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int splitAndConquer(vector<vector<int>>& grid, int row, int col, int size) {
        if (size == 1) return grid[row][col] < 0 ? 1 : 0;
        size/=2;
        return splitAndConquer(grid, row, col, size)
        + splitAndConquer(grid, row, col+size, size)
        + splitAndConquer(grid, row+size, col, size)
        + splitAndConquer(grid, row+size, col+size, size);
    }
    int countNegatives(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        if (m == 0) return 0;
        int n = (int)grid[0].size();
        if (m == n && m == 1) return grid[0][0] < 0 ? 1 : 0;

        if (m <= n) {
            if (n % 2) n++;
            for (auto &array : grid)
                while (array.size() < n) array.push_back(0);
            while (m < n) {
                vector<int> temp(n, 0);
                grid.push_back(temp);
                m++;
            }
        }
        
        if (m > n) {
            if (m % 2) m++;
            for (auto &array : grid)
                while (array.size() < m) array.push_back(0);
            n = m;
        }

        return splitAndConquer(grid, 0, 0, m);
    }
    
    /*
     暴力解法
     **/
//    int countNegatives(vector<vector<int>>& grid) {
//        int m, n;
//        m = (int)grid.size();
//        if (m == 0) return 0;
//        n = (int)grid[0].size();
//
//        int count = 0;
//        for (int i = 0; i < m; ++i)
//            for (int j = 0; j < n; ++j)
//                if (grid[i][j] < 0) count++;
//        return count;
//    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> grid = {
        {3,-1,-3,-3,-3},
        {2,-2,-3,-3,-3},
        {1,-2,-3,-3,-3},
        {0,-3,-3,-3,-3}
    };
    int result = s.countNegatives(grid);
    return 0;
}
