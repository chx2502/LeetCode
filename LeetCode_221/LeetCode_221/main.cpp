//
//  main.cpp
//  LeetCode_221
//
//  Created by chx on 2020/5/8.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = (int)matrix.size();
        if (m == 0) return 0;
        int n = (int)matrix[0].size();
        if (n == 0) return 0;
        
        int result = 0;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (matrix[row][col] == '0') continue;
                int left, up, leftUp, area;
                left = up = leftUp = 0;
                if (col > 0) left = matrix[row][col-1] - '0';
                if (row > 0) up = matrix[row-1][col] - '0';
                if (row > 0 && col > 0) leftUp = matrix[row-1][col-1] - '0';
                area = min({left, up, leftUp}) + 1;

                result = max(result, area);
                matrix[row][col] = '0'+area;
            }
        }
        return result*result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<char>> matrix = {
        {'1','1','0','1'},
        {'1','1','0','1'},
        {'1','1','1','1'},
    };
    int result = s.maximalSquare(matrix);
    return 0;
}
