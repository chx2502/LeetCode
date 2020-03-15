//
//  main.cpp
//  LeetCode_695_岛屿的最大面积
//
//  Created by chx on 2020/3/15.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     深度优先搜索。
     先在二维数组 grid 周围补一圈 2 作为边界，
     如此一来所有待遍历元素都具有上下左右四个方向，避免处理边界元素。
     dfs 遍历到的元素修改值为 2，面积 area 为 1，对其四个方向继续 dfs，area += 四个方向的面积。
     遇到 grid[row][col] != 1 则 area 为 0。
     记录遍历过程中最大的 area 作为返回值。
     **/
    void createBoundary(vector<vector<int>>& grid, int m, int n) {
        vector<int> horizon(n, 2);
        grid.insert(grid.begin(), horizon);
        grid.push_back(horizon);
        for (auto &array : grid) {
            array.insert(array.begin(), 2);
            array.push_back(2);
        }
    }
    
    int dfs(vector<vector<int>> &grid, int row, int col) {
        if (grid[row][col] != 1) return 0;
        int area = 1;
        grid[row][col] = 2;
        area += (
                 dfs(grid, row-1, col) +
                 dfs(grid, row+1, col) +
                 dfs(grid, row, col-1) +
                 dfs(grid, row, col+1)
                 );
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        if (m == 0) return 0;
        
        int n = (int)grid[0].size();
        createBoundary(grid, m, n);
        int max_area = 0;
        
        for (int row = 1; row <= m; ++row) {
            for (int col = 1; col <= n; ++col) {
                if (grid[row][col] == 1) {
                    int area = dfs(grid, row, col);
                    max_area = max_area < area ? area : max_area;
                } else continue;
            }
        }
        return max_area;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> grid = {{1}};
    int area = s.maxAreaOfIsland(grid);
    return 0;
}
