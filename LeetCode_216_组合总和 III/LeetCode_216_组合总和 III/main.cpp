//
//  main.cpp
//  LeetCode_216_组合总和 III
//
//  Created by chx on 2020/4/14.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    
    void backTracking(vector<int>& curr, vector<int>& nums, int begin, int n, int k, vector<vector<int>>& result) {
        if (curr.size() == k) {
            // 数组求和结果为 n 则该答案有效，加入 result
            if (accumulate(curr.begin(), curr.end(), 0) == n)
                result.push_back(curr);
            return;
        }
        
        for (int i = begin; i <= 9; ++i) {
            // 剪枝
            if (accumulate(curr.begin(), curr.end(), 0) >= n) continue;
            curr.push_back(nums[i]);
            // 若要全排列，则需要用到前面的元素，需要将前面的元素交换过来
//            swap(nums[begin], nums[i]);
            // 若要使用前面的元素，则 begin 的意义变为此时填入的是第 begin 个数，i+1 要变为 begin+1
            backTracking(curr, nums, i+1, n, k, result);
            // 相应地，交换也要被回退
//            swap(nums[begin], nums[i]);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if (k == 0 || k > 9 || n > 55) return result;
        
        vector<int> nums;
        for (int i = 0; i <= 9; ++i)
            nums.push_back(i);
        
        vector<int> curr;
        backTracking(curr, nums, 1, n, k, result);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int k = 3;
    int n = 11;
    vector<vector<int>> result = s.combinationSum3(k, n);
    return 0;
}
