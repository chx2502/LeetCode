//
//  main.cpp
//  LeetCode_55_跳跃游戏
//
//  Created by 成鑫 on 2019/8/8.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     动态规划。
     dp 数组存放每个下标位置能否到达最后一个位置，故 dp[size-1] = true
     destination 存储最近的能到达终点的下标值
     反向遍历 [size-1, 0]，当前下标 i 能到达的最远下标为 nums[i] + i
     对于每个下标 i:
         if : nums[i] + i >= destination;
         then: dp[i] = true; destination = i;
         return dp[0]
     **/
    bool canJump(vector<int>& nums) {
        int size = (int)nums.size();
        if (size <= 1) return true;
        
        vector<bool> dp(size, false);
        dp[size-1] = true;
        int destination = size-1;
        for (int i = size-2; i >= 0; --i) {
            if (nums[i] + i >= destination) {
                dp[i] = true;
                destination = i;
            }
        }
        return dp[0];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> test = {2, 3, 1, 1, 4};
    Solution s;
    bool result = s.canJump(test);
    return 0;
}
