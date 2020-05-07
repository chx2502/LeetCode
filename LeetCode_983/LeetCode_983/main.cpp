//
//  main.cpp
//  LeetCode_983
//
//  Created by chx on 2020/5/6.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int size = days.back()+1;
        vector<int> dp(size, 0);
        
        int isTravelDay = 0;
        for (int i = 1; i < size; ++i) {
            if (i == days[isTravelDay]) {
                int day1, day7, day30;
                day1 = i-1;
                day7 = i-7 > 0 ? i-7 : 0;
                day30 = i-30 > 0 ? i-30 : 0;
                int money = INT_MAX;
                money = min(money, dp[day1] + costs[0]);
                money = min(money, dp[day7] + costs[1]);
                money = min(money, dp[day30] + costs[2]);
                dp[i] = money;
                isTravelDay += 1;
            } else dp[i] = dp[i-1];
        }
        return dp[size-1];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> days = {1,2,3,4,6,8,9,10,13,14,16,17,19,21,24,26,27,28,29};
    vector<int> costs = {3, 14, 50};
    int result = s.mincostTickets(days, costs);
    return 0;
}
