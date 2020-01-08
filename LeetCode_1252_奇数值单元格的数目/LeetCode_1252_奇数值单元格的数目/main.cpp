//
//  main.cpp
//  LeetCode_1252_奇数值单元格的数目
//
//  Created by chx on 2019/12/8.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        /*
         常规思路：
         先变换，再逐个检查奇数
         **/
        vector<vector<int>> matrix;
        for (int i = 0; i < n; i++) {
            vector<int> temp(m, 0);
            matrix.push_back(temp);
        }
        for (auto &tuple : indices) {
            int row = tuple[0];
            int col = tuple[1];
            for (auto &num : matrix[row]) ++num;
            for (auto &array : matrix) ++array[col];
        }
        
        int count = 0;
        for (auto &array : matrix) {
            for (auto &num : array) {
                if (num % 2 != 0)
                    ++count;
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int n, m;
    n = 2;
    m = 3;
    vector<vector<int>> indices = {{0, 1}, {1, 1}};
    int result = s.oddCells(n, m, indices);
    return 0;
}
