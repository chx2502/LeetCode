//
//  main.cpp
//  LeetCode_377
//
//  Created by chx on 2021/4/2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     优化：给 nums 排序提前终止第二层的无效循环，利用滚动数组 pre 减少空间使用
     **/
    int combinationSum4(vector<int>& nums, int target) {
        int size = (int)nums.size();
        if (size == 0 || target == 0) return 0;

        vector<unsigned long long> dp(target+1, 0);
        vector<unsigned long long> pre(target+1, 0);
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        pre[0] = 1;

        for (int j = 0; j <= target; j++) {
            for (auto x : nums) {
                if (j >= x) dp[j] += pre[j-x];
                else break;
            }
            pre[j] = dp[j];
        }
        
        return (int)dp[target];
    }
    
    /*
     优化前
     **/
//    int combinationSum4(vector<int>& nums, int target) {
//        int size = (int)nums.size();
//        if (size == 0 || target == 0) return 0;
//        int len = target;
//        vector<vector<unsigned long long>> dp(len+1, vector<unsigned long long>(target+1, 0));
//        dp[0][0] = 1;
//        int result = 0;
//        for (int i = 1; i <= len; i++) {
//            for (int j = 0; j <= target; j++) {
//                for (auto x : nums) {
//                    if (j >= x) dp[i][j] += dp[i-1][j-x];
//                }
//            }
//            result += dp[i][target];
//        }
//        return result;
//    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 2, 3};
    int target = 4;
    Solution s;
    int res = s.combinationSum4(nums, target);
    return 0;
}
