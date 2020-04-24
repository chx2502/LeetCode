//
//  main.cpp
//  LeetCode_542_01 矩阵
//
//  Created by chx on 2020/4/15.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    const int INF = INT_MAX-1;
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> result;
        int m, n;
        m = (int)matrix.size();
        if (m == 0) return matrix;
        n = (int)matrix[0].size();
        if (n == 0) return matrix;
        
        result = vector<vector<int>>(m, vector<int>(n, INF));
        for (int row = 0; row < m; ++row)
            for (int col = 0; col < n; ++col)
                if (matrix[row][col] == 0)
                    result[row][col] = 0;
        for (int row = 0; row < m; ++row)
            for (int col = 0; col < n; ++col) {
                if (col-1 >= 0)
                    result[row][col] = min(result[row][col], result[row][col-1]+1);
                if (row-1 >= 0)
                    result[row][col] = min(result[row][col], result[row-1][col]+1);
            }
        
        for (int row = m-1; row >= 0; --row)
            for (int col = n-1; col >= 0; --col) {
                if (col+1 < n)
                    result[row][col] = min(result[row][col], result[row][col+1]+1);
                if (row+1 < m)
                    result[row][col] = min(result[row][col], result[row+1][col]+1);
            }
        
        return result;
    }
//    void printMatrix(vector<vector<int>>& matrix, int m, int n) {
//        for (int row = 0; row < m; ++row) {
//            for (int col = 0; col < n; ++col) {
//                cout << matrix[row][col] << " ";
//            }
//            cout << endl;
//        }
//    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> matrix = {
        {1,0,1,0,1,1,1,1,1,1},
        {0,1,0,1,1,0,0,0,0,1},
        {0,0,1,0,1,1,1,0,1,0},
        {0,1,0,1,0,1,0,0,1,1},
        {1,0,0,0,1,1,1,1,0,1},
        {1,1,1,1,1,1,1,0,1,0},
        {1,1,1,1,0,1,0,0,1,1},
    };
    vector<vector<int>> result = s.updateMatrix(matrix);
    
    return 0;
}
