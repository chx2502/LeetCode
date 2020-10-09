//
//  main.cpp
//  LeetCode_494
//
//  Created by chx on 2020/9/30.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int size = (int)nums.size();
        vector<int> dp(2001, 0);
        dp[1000 + nums[0]] = 1;
        dp[1000 - nums[0]] += 1;
        for (int i = 1; i < size; i++) {
            vector<int> temp(2001, 0);
            for (int j = -1000; j <= 1000; j++) {
                int bias = j+1000;
                if (dp[bias] > 0) {
                    temp[bias + nums[i]] += dp[bias];
                    temp[bias - nums[i]] += dp[bias];
                }
            }
            dp.assign(temp.begin(), temp.end());
        }
        return S > 1000 ? 0 : dp[S+1000];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1};
    int result = s.findTargetSumWays(nums, 3);
    return 0;
}
