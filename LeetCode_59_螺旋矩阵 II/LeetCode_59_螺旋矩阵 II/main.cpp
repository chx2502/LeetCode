//
//  main.cpp
//  LeetCode_59_螺旋矩阵 II
//
//  Created by chx on 2019/11/8.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n,vector<int>(n, 0));
        int max = n * n ;
        int curr = 1;
        int top, bottom, left, right;
        int col, row;
        
        top = left = 0;
        bottom = right = n-1;
        row = col = 0;
    
        while (curr <= max) {
            for (int i = left; i <= right; i++) {
                ret[top][i] = curr++;
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                ret[i][right] = curr++;
            }
            right--;
            for (int i = right; i >= left; i--) {
                ret[bottom][i] = curr++;
            }
            bottom--;
            for (int i = bottom; i >= top; i--) {
                ret[i][left] = curr++;
            }
            left++;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> result = s.generateMatrix(4);
    for (auto array : result) {
        for (auto i : array) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
