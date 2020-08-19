//
//  main.cpp
//  LeetCode_647
//
//  Created by chx on 2020/8/19.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int length = (int)s.length();
        if (length == 0) return 0;
        vector<vector<bool>> dp(length, vector<bool>(length, false));
        
        int result = 0;
        for (int i = 0; i < length; i++) {
            dp[i][i] = true;
            result += 1;
        }
        
        for (int i = length-2; i >= 0; i--) {
            for (int j = i+1; j < length; j++) {
                if ((i+1 >= j-1 || dp[i+1][j-1] == true) && s[i] == s[j]) {
                    cout << i << " " << j << endl;
                    cout << s.substr(i, j-i+1) << endl;
                    dp[i][j] = true;
                    result += 1;
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solve;
    string s  = "aabaccaba";
    int result = solve.countSubstrings(s);
    cout << "result = " << result << endl;
    return 0;
}
