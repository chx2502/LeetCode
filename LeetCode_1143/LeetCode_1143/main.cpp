//
//  main.cpp
//  LeetCode_1143
//
//  Created by chx on 2021/3/5.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1, len2;
        len1 = (int)text1.length();
        len2 = (int)text2.length();

        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[len1][len2];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
