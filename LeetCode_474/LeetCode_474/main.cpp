//
//  main.cpp
//  LeetCode_474
//
//  Created by chx on 2021/4/2.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string, vector<int>> memory;
    
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        for (const string &s : strs) {
//            int zeroCount, oneCount;
//            zeroCount = oneCount = 0;
//            for (const char &c : s) {
//                if (c == '0') zeroCount++;
//                else oneCount++;
//            }
//            memory[s] = {zeroCount, oneCount};
//        }
//        int size = (int)strs.size();
//        vector<vector<vector<int>>> dp(size+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
//
//        for (int i = 1; i <= size; i++) {
//            string curr = strs[i-1];
//            int zero = memory[curr][0];
//            int one = memory[curr][1];
//
//            // 可用状态压缩优化
//            for (int j = 0; j <= m; j++) {
//                for (int k = 0; k <= n; k++) {
//                    if (j < zero || k < one) dp[i][j][k] = dp[i-1][j][k];
//                    else {
//                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-zero][k-one]+1);
//                    }
//                }
//            }
//        }
//        return dp[size][m][n];
//    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        for (const string &s : strs) {
            int zeroCount, oneCount;
            zeroCount = oneCount = 0;
            for (const char &c : s) {
                if (c == '0') zeroCount++;
                else oneCount++;
            }
            memory[s] = {zeroCount, oneCount};
        }
        int size = (int)strs.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i = 1; i <= size; i++) {
            string curr = strs[i-1];
            int zero = memory[curr][0];
            int one = memory[curr][1];
            
            // 状态压缩优化内存使用【
            for (int j = m; j >= zero; j--) {
                for (int k = n; k >= one; k--) {
                    dp[j][k] = max(dp[j][k], dp[j-zero][k-one]+1);
                }
            }
        }
        return dp[m][n];
    }
};

int main(int argc, const char * argv[]) {
    vector<string> strs = { "10", "1", "0" };
    int m = 1;
    int n = 1;
    Solution s;
    int result = s.findMaxForm(strs, m, n);
    return 0;
}
