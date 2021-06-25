#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int maxProfit = accumulate(profit.begin(), profit.end(), 0);
        // int maxWorker = min(accumulate(group.begin(), group.end(), 0), n);
        if (maxProfit < minProfit) return 0;

        int size = (int)group.size();
        // dp[i][j][k] 表示第 i 种工作有 j 利润 和 k 名员工时的情况
        // dp[i][j][k] 由 dp[i-1][j-profit[i-1]][k-group[i-1]] 或 dp[i-1][j][k] 转移而来
        vector<vector<vector<ll>>> dp(size+1, vector<vector<ll>>(maxProfit+1, vector<ll>(n+1, 0)));
        dp[0][0][0] = 1;
        ll result = 0;
        const int MOD = 1e9 + 7;
        for (int i = 1; i <= size; i++) {
            int p = profit[i-1];
            int g = group[i-1];
            for (int j = maxProfit; j >= 0; j--) {
                for (int k = n; k >= 0; k--) {
                    if (k < g) dp[i][j][k] = dp[i-1][j][k];
                    else {
                        dp[i][j][k] = dp[i-1][j][k] + dp[i-1][max(0, j-p)][k-g];
                        dp[i][j][k] %= MOD;
                    }
                    // if (j >= minProfit && dp[i][j][k] > 0) printf("dp[%d][%d][%d] = %lld\n", i, j, k, dp[i][j][k]);
                }
            }
        }
        for (int i = 0; i <= n; i++) result += dp[size][minProfit][i];
        return result;
    }
};

int main () {
    vector<int> group = {2, 3, 5};
    vector<int> profit = {6, 7, 8};
    int n = 10;
    int minProfit = 5;
    Solution s;
    int result = s.profitableSchemes(n, minProfit, group, profit);
    cout << result << endl;
}