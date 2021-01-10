//
//  main.cpp
//  LeetCode_123
//
//  Created by chx on 2021/1/9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = (int)prices.size();
        if (days < 2) return 0;
        int liquidation = 0;
        int hold = 1;
        prices.insert(prices.begin(), 0);
        vector<vector<vector<int>>> dp(days+1, vector<vector<int>>(2, vector<int>(2, 0)));
        dp[0][0][liquidation] = 0;
        dp[0][1][liquidation] = dp[0][1][hold] = dp[0][0][hold] = INT_MIN;
        for (int today = 1; today <= days; today++) {
            int lastday = today-1;
            dp[today][0][hold] = max(dp[lastday][0][hold], -prices[today]);
            dp[today][0][liquidation] = max(dp[lastday][0][liquidation], dp[lastday][0][hold]+prices[today]);
            dp[today][1][hold] = max(dp[lastday][1][hold], dp[lastday][0][liquidation]-prices[today]);
            dp[today][1][liquidation] = max(dp[lastday][1][liquidation], dp[lastday][1][hold]+prices[today]);
        }
        return max(dp[days][0][liquidation], dp[days][1][liquidation]);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
