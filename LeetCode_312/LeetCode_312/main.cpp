//
//  main.cpp
//  LeetCode_312
//
//  Created by chx on 2020/7/19.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = (int)nums.size();
        vector<int> val(nums.begin(), nums.end());
        val.insert(val.begin(), 1);
        val.push_back(1);
        vector<vector<int>> dp(size+2, vector<int>(size+2, 0));
        
        for (int i = size; i >= 0; i--) {
            for (int j = i+2; j <= size+1; j++) {
                int temp = 0;
                int max = -1;
                for (int k = i+1; k < j; k++) {
                    temp = dp[i][k] + dp[k][j] + val[i]*val[k]*val[j];
                    if (max < temp) {
                        max = temp;
                    }
                }
                dp[i][j] = max;
                printf("dp[%d][%d] = %d\n", i, j, max);
            }
        }
        return dp[0][size+1];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {3, 1, 5, 8, 2, 4};
    int result = s.maxCoins(nums);
    return 0;
}
