//
//  main.cpp
//  LeetCode_188
//
//  Created by chx on 2021/1/10.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = (int)prices.size();
        if (k == 0 || days < 2) return 0;
        if (k > days/2) return maxProfit(days/2, prices);
        vector<vector<vector<int>>> dp(days, vector<vector<int>>(k+1, vector<int>(2, 0)));

        for (int i = 0; i < days; i++) {
            for (int j = k; j >=1; j--) {
                if (i == 0) {
                    dp[i][j][1] = -prices[i];
                    dp[i][j][0] = 0;
                    continue;
                }
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
            }
        }
        return dp[days-1][k][0];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> prices = { 3,2,6,5,0,3 };
    int k = 2;
    int result = s.maxProfit(k, prices);
    return 0;
}
