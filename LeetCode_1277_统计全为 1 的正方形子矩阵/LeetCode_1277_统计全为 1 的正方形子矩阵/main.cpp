//
//  main.cpp
//  LeetCode_1277_统计全为 1 的正方形子矩阵
//
//  Created by chx on 2019/12/12.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     对每一个元素，如果值为 1，则 count += 1，同时以该元素为起点，计算2 x 2, 3 x 3， k x k...的值
     如果计算过程中出现 0 元素，停止计算，跳到下一个元素
     计算完成后，子矩阵元素之和应等于 k*k， count += 1
     **/
    int countSquares(vector<vector<int>>& matrix) {
        const int m = (int)matrix.size();
        if (m == 0) return 0;
        const int n = (int)matrix[0].size();
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) ++count;
                else continue;
                for (int k = 2; i+k <= m && j+k <= n; ++k) {
                    bool flag = false;
                    int temp = 0;
                    int row, col;
                    row = i;
                    while (row < i+k) {
                        col = j;
                        while (col < j+k) {
                            if (matrix[row][col] == 0) {
                                flag = true;
                                break;
                            }
                            temp += matrix[row][col];
                            col++;
                        }
                        if (flag) break;
                        row++;
                    }
                    if (flag) break;
                    if (temp == k*k) ++count;
                }
            }
        }
        return count;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> matrix = {{1,0,1}, {1,1,0}, {1,1,0}};
    int result = s.countSquares(matrix);
    return 0;
}
