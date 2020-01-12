//
//  main.cpp
//  LeetCode_867_转置矩阵
//
//  Created by chx on 2020/1/12.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m, n;
        m = (int)A.size();
        n = (int)A[0].size();
        vector<vector<int>> res;
        for (int col = 0; col < n; ++col) {
            vector<int> temp;
            for (int row = 0; row < m; ++row) {
                temp.push_back(A[row][col]);
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
