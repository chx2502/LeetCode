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
    
//    int minDistance(string word1, string word2) {
//        int m = (int)word1.size();
//        int n = (int)word2.size();
//        if (m == 0) return n;
//        if (n == 0) return m;
//        vector<vector<int>> dp(m+1);
//        for (auto &array : dp)
//            array = vector<int>(n+1, 0);
//        for (int i = 1; i <= m; ++i)
//            dp[i][0] = i;
//        for (int j = 1; j <= n; ++j)
//            dp[0][j] = j;
//
//        for (int i = 1; i <= m; ++i) {
//            for (int j = 1; j <= n; ++j) {
//                if (word1[i-1] == word2[j-1])
//                    dp[i][j] = dp[i-1][j-1];
//                else {
//                    dp[i][j] = min(
//                                   min(dp[i][j-1], dp[i-1][j]),
//                                   min(dp[i-1][j], dp[i-1][j-1])
//                                   ) + 1;
//                }
//            }
//        }
//        return dp[m][n];
//    }
    /*
     递归解法
     **/
    vector<vector<int>> memory;
    
    int dp(int i, int j, const string &word1, const string &word2) {
        if (memory[i][j] != 501) return memory[i][j];
        
        if (i == 0) return j;
        if (j == 0) return i;
        
        if (word1[i-1] == word2[j-1]) {
            memory[i][j] = dp(i-1, j-1, word1, word2);
        } else {
            memory[i][j] = min({dp(i, j-1, word1, word2)+1, dp(i-1, j, word1, word2)+1, dp(i-1, j-1, word1, word2)+1});
        }
        return memory[i][j];
    }
    
    int minDistance(string word1, string word2) {
        int m = (int)word1.length();
        int n = (int)word2.length();
        
        if (m == 0) return n;
        if (n == 0) return m;
        
        memory.assign(m+1, vector<int>(n+1, 501));
        memory[0][0] = 0;
        return dp(m, n, word1, word2);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string s1 = "intention";
    string s2 = "execution";
    int result = s.minDistance(s1, s2);
    return 0;
}
