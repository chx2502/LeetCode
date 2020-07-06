//
//  main.cpp
//  LeetCode_63
//
//  Created by chx on 2020/7/6.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     中间的计算过程中会出现比 2^16 大的数导致溢出，需要单独开一个二维数组存放 long
     **/
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = (int)obstacleGrid.size();
        if (m == 0) return 0;
        int n = (int)obstacleGrid[0].size();
        if (n == 0) return 0;
        if (obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) return 0;
        
        
        vector<vector<long>> matrix;
        for (auto &array : obstacleGrid) {
            vector<long> temp;
            for (auto &num : array)
                temp.push_back(num);
            matrix.push_back(temp);
        }
        
        matrix[m-1][n-1] = -1;

        for (int row = m-1; row >= 0; --row) {
            for (int col = n-1; col >= 0; --col) {
                long curr = matrix[row][col];
                if (curr == 1) continue;
                if (col > 0 && matrix[row][col-1] != 1) matrix[row][col-1] += curr;
                if (row > 0 && matrix[row-1][col] != 1) matrix[row-1][col] += curr;
            }
        }
        return -matrix[0][0];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    int result = s.uniquePathsWithObstacles(obstacleGrid);
    return 0;
}
