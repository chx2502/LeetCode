//
//  main.cpp
//  LeetCode_491
//
//  Created by chx on 2020/8/25.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    unordered_map<int, bool> M;
    void backTracking(int curr, vector<int>& nums, vector<int>& ans) {
        int size = (int)nums.size();
        if (ans.size() > 1) {
            int hashValue = getHashValue(ans, 201, 1e9+7);
            if (M.find(hashValue) == M.end()) {
                result.push_back(ans);
                M[hashValue] = true;
            }
        }
        if (curr >= size) return;
        int back = -101;
        if (ans.size()) back = ans.back();
        for (int i = curr+1; i < size; i++) {
            if (nums[i] >= back) {
                ans.push_back(nums[i]);
                backTracking(i, nums, ans);
                ans.pop_back();
            }
        }
    }
    
    // 自定义 hash 函数
    int getHashValue(vector<int>& ans, int base, int mod) {
        int hashValue = 0;
        for (const auto &num : ans) {
            hashValue = 1LL * hashValue * base % mod + (num+101);
            hashValue %= mod;
        }
        return hashValue;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int size = (int)nums.size();
        if (size < 2) return result;
        
        vector<int> ans;
        backTracking(-1, nums, ans);
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    vector<int> nums = {4, 6, 7, 7};
    
    vector<vector<int>> result = s.findSubsequences(nums);
    return 0;
}
