//
//  main.cpp
//  LeetCode_62
//
//  Created by chx on 2020/4/25.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    /*
     从右下角往左上角更新，dp[i][j] = dp[i+1][j] + dp[i][j+1]
     **/
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = 1;
        
        for (int row = m-1; row >= 0; --row)
            for (int col = n-1; col >= 0; --col) {
                if (row < m-1) dp[row][col] += dp[row+1][col];
                if (col < n-1) dp[row][col] += dp[row][col+1];
            }
        
        return dp[0][0];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int result = s.uniquePaths(3, 7);
    return 0;
}
