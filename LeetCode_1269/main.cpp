#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void printDP(vector<vector<int>>& dp) {
        for (auto &arr : dp) {
            for (auto &num : arr) {
                cout << num << " ";
            }
            cout << endl;
        }
        cout << "------------------------" << endl;
    }
    int numWays(int steps, int arrLen) {
        const int MOD = 1e9+7;
        if (steps <= 1 || arrLen == 1) return 1;

        int limit = min(steps/2, arrLen-1);
        
        // vector<vector<long long>> dp(steps+1, vector<long long>(limit+2, 0));
        // dp[0][0] = 1;

        vector<long long> dp(limit+2, 0);
        vector<long long> pre(limit+2, 0);
        pre[0] = 1;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j <= limit; j++) {
                // if (j < 1) dp[i][j] = dp[i-1][j] + dp[i-1][j+1];
                // else dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                // dp[i][j] %= MOD;

                if (j < 1) dp[j] = pre[j] + pre[j+1];
                else dp[j] = pre[j-1] + pre[j] + pre[j+1];
                dp[j] %= MOD;
                // printDP(dp);
            }
            pre = dp;
        }
        // return dp[steps][0];
        return dp[limit];
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int steps = 3;
    int arrLen = 2;
    int result = s.numWays(steps, arrLen);
    cout << result << endl;
    return 0;
}
