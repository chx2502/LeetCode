//
//  main.cpp
//  LeetCode_面试题63_股票的最大利润
//
//  Created by chx on 2020/3/5.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     此解法太慢
     **/
//    int maxProfit(vector<int>& prices) {
//        int length = (int)prices.size();
//        int left, right, max;
//        left = 0;
//        right = length;
//        max = 0;
//        while (left < right) {
//            int profit = prices[right] - prices[left];
//            max = profit > max ? profit : max;
//            right--;
//            if (right == left && left < length-2) {
//                int temp = prices[left++];
//                while (temp < prices[left] && left < length-2) left++;
//                right = length-1;
//            }
//        }
//        return max;
//    }
    /*
     思路：
     逆序遍历
     max 用来标记从尾部到目前位置 i 的最大值
     profit 用来标记在目前位置 i 买入的利润
     result 用来记录最高利润
     profit < 0 : 当前位置 i 的股票价格更高，作为 max
     profit >= 0 : 与 result 比较，若大于 result 则更新 result
     **/
    int maxProfit(vector<int>& prices) {
        int length = (int)prices.size();
        if (length < 2) return 0;
        
        int max = prices[length-1];
        int profit = 0;
        int result = 0;
        for (int i = length-2; i >=0; i--) {
            profit = max-prices[i];
            if (profit < 0) max = prices[i];
            else result = profit > result ? profit : result;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
