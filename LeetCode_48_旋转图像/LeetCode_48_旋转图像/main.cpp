//
//  main.cpp
//  LeetCode_48_旋转图像
//
//  Created by chx on 2020/1/19.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     先转置再翻转。
     **/
    void rotate(vector<vector<int>>& matrix) {
        int m, n;
        m = (int)matrix.size();
        n = (int)matrix[0].size();

        // 转置
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < n; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // 翻转
        for (int j = 0; j < n; ++j) {
            int left, right;
            left = j;
            right = n - left - 1;
            if (right <= left) continue;
            for (int i = 0; i < m; ++i) {
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    Solution s;
    s.rotate(matrix);
    return 0;
}
