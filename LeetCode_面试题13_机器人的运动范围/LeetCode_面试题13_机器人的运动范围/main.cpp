//
//  main.cpp
//  LeetCode_面试题13_机器人的运动范围
//
//  Created by chx on 2020/4/8.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<bool>> visited;
    int sum(int x) {
        int sum = 0;
        while (x) {
            sum += x%10;
            x /= 10;
        }
        return sum;
    }
    void dfs(int row, int col, int m, int n, int k, int &count) {
        if (row >= m || col >= n) return;
        if (visited[row][col]) return;
        visited[row][col] = true;
        if (sum(row) + sum(col) <= k) {
            count += 1;
            dfs(row, col+1, m, n, k, count);
            dfs(row+1, col, m, n, k, count);
        }
    }
    int movingCount(int m, int n, int k) {
        int result = 0;
        visited = vector<vector<bool>>(m);
        for (auto &array : visited)
            array = vector<bool>(n, false);
        dfs(0, 0, m, n, k, result);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int m, n, k;
    m = 14;
    n = 14;
    k = 5;
    int result = s.movingCount(m, n, k);
    return 0;
}
