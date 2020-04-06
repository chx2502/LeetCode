//
//  main.cpp
//  LeetCode_72_编辑距离
//
//  Created by chx on 2020/4/6.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 参考题解：https://www.cxyxiaowu.com/2775.html
    int minDistance(string word1, string word2) {
        int m = (int)word1.size();
        int n = (int)word2.size();
        if (m == 0) return n;
        if (n == 0) return m;
        vector<vector<int>> dp(m+1);
        for (auto &array : dp)
            array = vector<int>(n+1, 0);
        for (int i = 1; i <= m; ++i)
            dp[i][0] = i;
        for (int j = 1; j <= n; ++j)
            dp[0][j] = j;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = min(
                                   min(dp[i][j-1], dp[i-1][j]),
                                   min(dp[i-1][j], dp[i-1][j-1])
                                   ) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
