//
//  main.cpp
//  LeetCode_309
//
//  Created by chx on 2020/7/10.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     状态机解法：
     非冷冻期下可选择“持有”或“买入/卖出”
     冷冻期只能选择“休息”
     
     以每天结束时的情况划分出 3 种状态
     状态 0 --- 无股票且可买入，由状态 1 经“休息”后转入，或者由状态 0 经“持有”后转入
     状态 1 --- 有股票且可卖出，由状态 0 经“买入”后转入，或者由状态 1 经“持有”后转入
     状态 2 --- 无股票且无法买入，由状态 2 经“卖出”后转入
     **/
    int maxProfit(vector<int>& prices) {
        int size = (int)prices.size();
        if (size == 0) return 0;
        vector<vector<int>> dp(size, vector<int>(3, 0));
        dp[0][1] = -prices[0];
        
        int pre_0 = 0;
        int pre_1 = 0;
        for (int i = 1; i < size; ++i) {
            int curr_price = prices[i];
            pre_0 = dp[i-1][0];
            pre_1 = dp[i-1][1];
            dp[i][0] = max(pre_0, dp[i-1][2]);
            dp[i][1] = max((pre_0 - curr_price), pre_1);
            dp[i][2] = pre_1 + curr_price;
        }
        return max({ dp[size-1][0], dp[size-1][1], dp[size-1][2] });
    }
};

int main(int argc, const char * argv[]) {
    vector<int> prices = {1, 2, 3, 0, 2};
    Solution s;
    int resutl = s.maxProfit(prices);
    return 0;
}
