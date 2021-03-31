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
public:
    /*
     O(n^2) 解法
     **/
//    int lengthOfLIS(vector<int>& nums) {
//        int size = (int)nums.size();
//        if (size == 0) return 0;
//        vector<int> dp(size, 0);
//        int result = 1;
//        dp[0] = 1;
//        for (int i = 1; i < size; ++i) {
//            dp[i] = 1;
//            for (int j = 0; j < i; ++j) {
//                if (nums[j] < nums[i]) {
//                    dp[i] = max(dp[i], dp[j]+1);
//                    result = result < dp[i] ? dp[i] : result;
//                }
//            }
//        }
//
//        return result;
//    }
    /*
     O(nlogn) 解法
     非常规解法，正常人想不到
     **/
    int lengthOfLIS(vector<int>& nums) {
        int size = (int)nums.size();
        
        vector<int> top(size, 0);
        int piles = 0;
        for (int i = 0; i < size; i++) {
            int curr = nums[i];
            int begin, end;
  
            begin = 0;
            end = piles;
            while (begin < end) {
                int mid = begin + (end-begin) / 2;
                if (top[mid] >= curr) end = mid;
                else begin = mid + 1;
            }
            if (begin == piles) piles++;
            top[begin] = curr;
        }
        return piles;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {4, 10, 4, 3, 8, 9};
    s.lengthOfLIS(nums);
    return 0;
}
