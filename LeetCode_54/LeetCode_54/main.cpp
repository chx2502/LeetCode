//
//  main.cpp
//  LeetCode_54
//
//  Created by chx on 2020/7/13.
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
        
        int top, bottom, left, right;
        top = left = 0;
        bottom = m-1;
        right = n-1;
        int row, col;
        row = col = 0;
        while (left <= right && top <= bottom) {
            for (col = left; col <= right; col++) result.push_back(matrix[top][col]);
            for (row = top+1; row <= bottom; row++) result.push_back(matrix[row][right]);
            if (left < right && top < bottom) {
                for (col = right-1; col > left; col--) result.push_back(matrix[bottom][col]);
                for (row = bottom; row > top; row--) result.push_back(matrix[row][left]);
            }
            top++;
            bottom--;
            left++;
            right--;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    Solution s;
    vector<int> result = s.spiralOrder(matrix);
    return 0;
}
