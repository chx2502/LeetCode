//
//  main.cpp
//  LeetCode_115
//
//  Created by chx on 2021/3/17.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int lenS = (int)s.length();
        int lenT = (int)t.length();
        
        vector<vector<long>> dp(lenS+1, vector<long>(lenT+1, 0));
        
        for (int i = 0; i <= lenS; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= lenS; i++) {
            for (int j = 1; j <= lenT; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[lenS][lenT];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
