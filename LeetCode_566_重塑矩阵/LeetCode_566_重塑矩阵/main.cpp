//
//  main.cpp
//  LeetCode_566_重塑矩阵
//
//  Created by chx on 2020/2/16.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     解法 1:
     暴力法，提取全部数字后逐一填入新的二维数组。
     解法 2:
     参考：https://leetcode-cn.com/problems/reshape-the-matrix/solution/c-jian-dan-ti-jie-by-da-li-wang-35/
     **/
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row, col;
        row = (int)nums.size();
        col = (int)nums[0].size();
        if (row*col != r*c) return nums;
        
        vector<vector<int>> result;
        vector<int> storage;
        for (auto &array : nums)
            for (auto num : array)
                storage.push_back(num);
        
        int count = 0;
        for (int i = 0; i < r; i++) {
            vector<int> temp;
            for (int j = 0; j < c; j++) {
                temp.push_back(storage[count++]);
            }
            result.push_back(temp);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
