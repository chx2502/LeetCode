//
//  main.cpp
//  LeetCode_44
//
//  Created by chx on 2020/7/18.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_length = (int)s.length();
        int p_length = (int)p.length();
        if (s_length == p_length && p_length == 0) return true;
        
        vector<vector<bool>> dp(s_length+1, vector<bool>(p_length+1, false));
        for (int i = 1; i <= p_length; ++i) {
            if (p.at(i-1) != '*') break;
            dp[0][i] = true;
        }
        dp[0][0] = true;
        for (int i = 1; i <= s_length; ++i) {
            for (int j = 1; j <= p_length; ++j) {
                if (p[j-1] == s[i-1] || p.at(j-1) == '?') dp[i][j] = dp[i-1][j-1];
                else if (p.at(j-1) == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[s_length][p_length];
    }
};

int main(int argc, const char * argv[]) {
    Solution solve;
    string s = "adceb";
    string p = "*a*b";
    bool result = solve.isMatch(s, p);
    return 0;
}
