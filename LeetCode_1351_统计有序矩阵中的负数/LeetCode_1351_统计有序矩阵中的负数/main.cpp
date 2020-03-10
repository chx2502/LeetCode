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
        
    }
    int countNegatives(vector<vector<int>>& grid) {
        
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
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
