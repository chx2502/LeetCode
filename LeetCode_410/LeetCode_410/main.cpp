//
//  main.cpp
//  LeetCode_410
//
//  Created by chx on 2020/7/25.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int size = (int)nums.size();
        if (size == 1) return nums[0];
 
        vector<long> subSum(size+1, 0);
        for (int i = 1; i <= size; i++) subSum[i] += subSum[i-1] + nums[i-1];
        
        vector<vector<long>> dp(size+1, vector<long>(m+1, LLONG_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= i && j <= m; j++) {
                long curr_min = LLONG_MAX;
                for (int k = 0; k < i; k++) {
                    long temp = max(dp[k][j-1], subSum[i] - subSum[k]);
                    curr_min = curr_min < temp ? curr_min : temp;
                }
                dp[i][j] = curr_min;
            }
        }
        return (int)dp[size][m];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {7, 2, 5, 10, 8};
    int result = s.splitArray(nums, 2);
    return 0;
}
