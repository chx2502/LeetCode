//
//  main.cpp
//  LeetCode_97
//
//  Created by chx on 2020/7/18.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = (int)s1.size();
        int len2 = (int)s2.size();
        int len3 = (int)s3.size();
        if (len1 + len2 != len3) return false;
        
        vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, false));
        dp[0][0] = true;
        for (int i = 0; i <= len1; ++i) {
            for (int j = 0; j <= len2; ++j) {
                int curr = i + j - 1;
                if (i > 0) dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[curr]);
                if (j > 0 && ! dp[i][j]) dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[curr]);
            }
        }
        return dp[len1][len2];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    bool result = s.isInterleave(s1, s2, s3);
    return 0;
}
