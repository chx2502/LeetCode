#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * 动态规划 f(i) = 1 + min [ f(i-c) for c in coins ]
     * 优化：如果遇到 coin 值等于 amount 直接返回 1
     * dp[i] == amount + 1 为寻找失败标志
     * */
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount+1, amount+1);
        for (auto &num : coins) {
            if (num <= amount) dp[num] = 1;
        }
        if (dp[amount] == 1) return dp[amount];
        int i = 0;
        while (i++ < amount) {
            if (dp[i] < amount) continue;
            int min = amount +1;
            for (auto &num : coins) {
                if (i-num >= 0) {
                    int cost = dp[i-num];
                    min = min > cost ? cost : min;
                }
            }
            dp[i] = 1 + min;
        }
        return dp[amount] < amount+1 ? dp[amount] : -1;
    }
};

int main() {
    Solution s;
    vector<int> coins = {1, 5, 10};
    int result = s.coinChange(coins, INT_MAX-1);
    return 0;
}
