//
//  main.cpp
//  LeetCode_64_最小路径和
//
//  Created by chx on 2019/12/10.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     动态规划，参考官方题解4，在原数组上从终点出发更新各结点的路经长
     **/
//    int minPathSum(vector<vector<int>>& grid) {
//        const int m = (int)grid.size();
//        if (m == 0) return 0;
//        const int n = (int)grid[0].size();
//        int i, j;
//        i = m;
//        j = n-1;
//        while (i-- > 0) {
//            while (j-- > 0) {
//                if (i < m-1 && j < n-1)
//                    grid[i][j] += grid[i][j+1] < grid[i+1][j] ? grid[i][j+1] : grid[i+1][j];
//                else if (i < m-1)
//                    grid[i][j] += grid[i+1][j];
//                else
//                    grid[i][j] += grid[i][j+1];
//            }
//            j = n;
//        }
//        return grid[0][0];
//    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        if (m == 0) return 0;
        int n = (int)grid[0].size();
        if (n == 0) return 0;
        
        for (int row = m-1; row >=0; row--) {
            for (int col = n-1; col >= 0; col--) {
                if (row < m-1 && col < n-1) grid[row][col] += min(grid[row+1][col], grid[row][col+1]);
                else if (row < m-1) grid[row][col] += grid[row+1][col];
                else if (col < n-1) grid[row][col] += grid[row][col+1];
                else continue;
            }
        }
        return grid[0][0];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> grid = {{1, 3, 1},{1, 5, 1}, {4, 2, 1}};
    int result = s.minPathSum(grid);
    return 0;
}
