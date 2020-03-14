//
//  main.cpp
//  LeeTcode_300_最长上升子序列
//
//  Created by chx on 2020/3/14.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
//private:
//
//    int splitAndConquer(const vector<int>& nums, int begin, int end) {
//        if (begin == end-1) {
//            if (nums[begin] < nums[end]) return 2;
//            else return 0;
//        }
//        int mid = (begin + end) / 2;
//
//    }
public:
    /*
     O(n^2) 解法
     **/
    int lengthOfLIS(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0) return 0;
        vector<int> dp(size, 0);
        int result = 1;
        dp[0] = 1;
        for (int i = 1; i < size; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                    result = result < dp[i] ? dp[i] : result;
                }
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {4, 10, 4, 3, 8, 9};
    s.lengthOfLIS(nums);
    return 0;
}
