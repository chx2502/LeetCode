//
//  main.cpp
//  LeetCode_120_三角形最小路径和
//
//  Created by chx on 2019/12/12.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     思路参照 #64 中的官方题解：https://leetcode-cn.com/problems/minimum-path-sum/solution/
     原地更新每个元素的路径和值，先处理元素为边界的情况。
     **/
//    int minimumTotal(vector<vector<int>>& triangle) {
//        unsigned long height = triangle.size();
//        if (height == 0) return 0;
//        for (int i = 1; i < height; ++i) {
//            unsigned long length = triangle[i].size();
//            for (int j = 0; j < length; ++j) {
//                if (j == length-1) triangle[i][j] += triangle[i-1][j-1];
//                else if (j > 0) triangle[i][j] += triangle[i-1][j-1] < triangle[i-1][j] ? triangle[i-1][j-1] : triangle[i-1][j];
//                else triangle[i][j] += triangle[i-1][j];
//            }
//        }
//        int min = INT32_MAX;
//        for (auto &num : triangle[height-1]) {
//            if (num < min) {
//                min = num;
//            }
//        }
//        return min;
//    }
    // 从倒数第二行开始向上更新
    // triangle[level][i] += min(triangle[level+1][i], triangle[level+1][i+1])
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = (int)triangle.size();
        if (height == 0) return 0;
        for (int level = height-2; level >= 0; --level) {
            int size = (int)triangle[level].size();
            for (int i = 0; i < size; ++i) {
                triangle[level][i] += min(triangle[level+1][i], triangle[level+1][i+1]);
            }
        }
        return triangle[0][0];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int result = s.minimumTotal(triangle);
    return 0;
}
