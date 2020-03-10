//
//  main.cpp
//  LeetCode_121_买卖股票的最佳时机
//
//  Created by chx on 2020/3/9.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    /*
     动态规划，思路来自于 牛顿莱布尼兹公式。
     记录第 i 天相对于 i-1 天的涨跌，求得最大子列和即为最高涨幅情况下的利润
     **/
    int maxProfit(vector<int>& prices) {
        int length = (int)prices.size();
        if (length == 0) return 0;
        int max_profit = 0;
        int increase = 0;
        for (int i = 1; i < length; ++i) {
            increase = max(0, increase + prices[i] - prices[i-1]);
            max_profit = max(max_profit, increase);
        }
        return max_profit;
    }
    /*
     官方题解
     **/
//    int maxProfit(vector<int>& prices) {
//        int length = (int)prices.size();
//        if (length == 0) return 0;
//        int min = INT_MAX;
//        int max_profit = 0;
//        for (int i = 0; i < length; ++i) {
//            int price = prices[i];
//            int profit = price - min;
//            min = min > price ? price : min;
//            max_profit = max_profit < profit ? profit : max_profit;
//        }
//        return max_profit;
//    }
    /*
     递增栈解法
     **/
//    int maxProfit(vector<int>& prices) {
//        int length = (int)prices.size();
//        if (length == 0) return 0;
//        prices.push_back(-1);
//        deque<int> dq;
//        int max = 0;
//        for (auto &price : prices) {
//            while (!dq.empty() && dq.back() > price) {
//                int profit = dq.back() - dq.front();
//                max = profit > max ? profit : max;
//                dq.pop_back();
//            }
//            dq.push_back(price);
//        }
//        return max;
//    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
