//
//  main.cpp
//  LeetCode_807_保持城市天际线
//
//  Created by chx on 2020/2/26.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     元素增加后的值不能超过所在行和所在列原始的最大值。
     可增加的值 = min(行最大值, 列最大值) - 元素值。
     **/
    vector<int> maxOfRow(vector<vector<int>>& grid) {
        vector<int> result;
        for (auto &array : grid) {
            int max = INT_MIN;
            for (auto &num : array) {
                if (num > max) max = num;
            }
            result.push_back(max);
        }
        return result;
    };
    
    vector<int> maxOfCol(vector<vector<int>>& grid) {
        int m, n;
        m = (int)grid.size();
        n = (int)grid[0].size();
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            int max = INT_MIN;
            for (int j = 0; j < m; ++j) {
                int num = grid[j][i];
                if (num > max) max = num;
            }
            result.push_back(max);
        }
        return result;
    };
    
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m, n;
        m = (int)grid.size();
        n = (int)grid[0].size();
        if (m == 0) return 0;
        int result = 0;
        
        vector<int> row_max = maxOfRow(grid);
        vector<int> col_max = maxOfCol(grid);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int num = grid[i][j];
                int r = row_max[i];
                int c = col_max[j];
                int max = r < c ? r : c;
                result += max-num;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> grid = {
        { 3, 0, 8, 4 },
        { 2, 4, 5, 7 },
        { 9, 2, 6, 3 },
        { 0, 3, 1, 0},
    };
    int result = s.maxIncreaseKeepingSkyline(grid);
    return 0;
}
