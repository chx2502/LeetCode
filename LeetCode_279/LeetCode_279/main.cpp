//
//  main.cpp
//  LeetCode_279
//
//  Created by chx on 2021/4/2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 10001);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j*j <= i; j++) {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int n = 12;
    int result = s.numSquares(n);
    return 0;
}
