//
//  main.cpp
//  LeetCode_1227_飞机座位分配概率
//
//  Created by chx on 2019/12/9.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     递归解法:
     有个大坑，(n-2)/n * nthPnthPersonGetsNthSeat(n-1)
                和
             ((n-2) * nthPersonGetsNthSeat(n-1)) / n
     结果不一样
     **/
//    double nthPersonGetsNthSeat(int n) {
//        if (n == 1) return 1.0;
//        else return (double)1/n + ((n-2) * nthPersonGetsNthSeat(n-1)) / n;
//    }
    /*
     动态规划
     **/
    double nthPersonGetsNthSeat(int n) {
        if (n == 1) return 1.0;
        vector<double> dp(n+1, 0);
        dp[1] = 1.0;
        double i = 1;
        while (i++ < n) {
            dp[i] = 1/i + ((i-2)/i) * dp[i-1];
        }
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int n = 5;
    double result = s.nthPersonGetsNthSeat(n);
    return 0;
}
