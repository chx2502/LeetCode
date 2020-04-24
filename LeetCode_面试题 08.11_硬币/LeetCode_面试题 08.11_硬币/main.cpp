//
//  main.cpp
//  LeetCode_面试题 08.11_硬币
//
//  Created by chx on 2020/4/23.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    const int LIMIT = 1000000007;
    int waysToChange(int n) {
        if (n == 0) return 1;
        vector<int> dp(n+1, 0);
        vector<int> coins = {1, 5, 10, 25};
        dp[0] = 1;
        for (auto coin : coins) {
            for (int i = coin; i <= n; ++i) {
                dp[i] = (dp[i] + dp[i-coin]);
                if (dp[i] >= LIMIT) dp[i] %= LIMIT;
            }
        }
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int result = s.waysToChange(25);
    return 0;
}
