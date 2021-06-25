//
//  main.cpp
//  LeetCode_416
//
//  Created by chx on 2021/4/2.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
//    bool canPartition(vector<int>& nums) {
//        int sum = accumulate(nums.begin(), nums.end(), 0);
//        if (sum & 1) return false;
//        int N = sum / 2;
//
//        vector<vector<bool>> dp(nums.size()+1, vector<bool>(N+1, false));
//        dp[0][0] = true;
//
//        for (int i = 1; i <= nums.size(); i++) {
//            int curr = nums[i-1];
//            for (int j = 1; j <= N; j++) {
//                // dp[i] 之和 dp[i-1] 有关，可以进行状态压缩
//                if (j < curr) dp[i][j] = dp[i-1][j];
//                else dp[i][j] = dp[i-1][j] || dp[i-1][j-curr];
//            }
//            if (dp[i][N]) return true;
//        }
//        return false;
//    }
    
    // 状态压缩优化
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum & 1) == 1) return false;
        int N = sum / 2;

        vector<bool> dp(N+1, false);
        dp[0] = true;
        
        for (int i = 1; i <= nums.size(); i++) {
            int curr = nums[i-1];
            // 0-1背包状态压缩注意遍历顺序
            for (int j = N; j >= curr; j--) {
                dp[j] = dp[j] || dp[j-curr];
                if (dp[N]) return true;
            }
        }
        return dp[N];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 2, 5};
    bool result = s.canPartition(nums);
    return 0;
}
