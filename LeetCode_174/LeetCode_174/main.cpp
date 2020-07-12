//
//  main.cpp
//  LeetCode_174
//
//  Created by chx on 2020/7/12.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = (int)dungeon.size();
        if (m == 0) return 1;
        int n = (int)dungeon[0].size();
        if (n == 0) return 1;
        
        // 在 dunfeon 周围加上三条边界(没有上边界)
        const int INF = 0x3f3f3f3f;
        dungeon.push_back(vector<int>(n, INF));
        for (auto &array : dungeon) {
            array.insert(array.begin(), INF);
            array.push_back(INF);
        }
        
        // 以公主 P 所在的点为起点开始遍历，需要先初始化 P 点的右和下两个节点
        dungeon[m-1][n+1] = 1;
        dungeon[m][n] = 1;

        for (int row = m-1; row >= 0; --row) {
            for (int col = n; col > 0; --col) {
                int curr = dungeon[row][col];
                curr = min(dungeon[row][col+1], dungeon[row+1][col]) - curr;
                if (curr <= 0) dungeon[row][col] = 1;
                else dungeon[row][col] = curr;
            }
        }
        return dungeon[0][1];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    vector<vector<int>> duengeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    int result = s.calculateMinimumHP(duengeon);
    return 0;
}
