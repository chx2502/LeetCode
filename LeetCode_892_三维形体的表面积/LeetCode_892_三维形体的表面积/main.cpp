//
//  main.cpp
//  LeetCode_892_三维形体的表面积
//
//  Created by chx on 2020/3/25.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     对表面积进行增量更新，每经过一格，计算该格贡献的表面积。
     只需要考虑当前格子对上方和左边格子的遮挡。
     设格子 [row, col] 有 x 个立方体，
     自身面积：x * 6 - (x-1) * 2
     上方或左边遮挡：2 * (min(x, left||up))
     新增面积 = 自身面积 - 遮挡面积
     **/
    int currentSurfaceArea(vector<vector<int>>& grid, int row, int col) {
        int area = 0;
        int curr = grid[row][col];
        // 当前格子没有方块，直接返回 0
        if (curr == 0) return 0;
        int up = 0;
        int left = 0;
        if (row > 0) up = grid[row-1][col];
        if (col > 0) left = grid[row][col-1];
        area = curr*6 - ((curr-1) + min(curr, left) + min(curr, up))*2;
        return area;
    }
    int surfaceArea(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        if (n == 0) return 0;
        int result = 0;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                result += currentSurfaceArea(grid, row, col);
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
