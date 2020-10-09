//
//  main.cpp
//  LeetCode_面试题29_顺时针打印矩阵
//
//  Created by chx on 2020/6/5.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = (int)matrix.size();
        if (m == 0) return result;
        int n = (int)matrix[0].size();
        if (n == 0) return result;
        
        int left, right, top, bottom;
        left = top = 0;
        right = n-1;
        bottom = m-1;
        while (true) {
            int row = top++;
            for (int i = left; i <= right; ++i)
                result.push_back(matrix[row][i]);
            if (left > right || top > bottom) break;
            int col = right--;
            for (int i = top; i <= bottom; ++i)
                result.push_back(matrix[i][col]);
            if (left > right || top > bottom) break;
            row = bottom--;
            for (int i = right; i >= left; --i)
                result.push_back(matrix[row][i]);
            if (left > right || top > bottom) break;
            col = left++;
            for (int i = bottom; i >= top; --i)
                result.push_back(matrix[i][col]);
            if (left > right || top > bottom) break;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    Solution s;
    vector<int> result = s.spiralOrder(matrix);
    for (auto i : result) cout << i << " ";
    return 0;
}
