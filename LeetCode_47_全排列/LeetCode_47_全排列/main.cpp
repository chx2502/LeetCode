//
//  main.cpp
//  LeetCode_47_全排列
//
//  Created by chx on 2020/4/19.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    void backTracking(
                      vector<int>& curr,
                      int begin,
                      int size,
                      vector<int> used,
                      vector<int>& nums,
                      vector<vector<int>>& result
                      )
    {
        if (begin == size) {
            result.push_back(curr);
            return;
        }
        
        for (int i = 0; i < size; ++i) {
            if (used[i]) continue;
            if (i > 0 && nums[i-1] == nums[i] && !used[i-1]) {
                continue;
            }
            curr.push_back(nums[i]);
            used[i] = 1;
            backTracking(curr, begin+1, size, used, nums, result);
            used[i] = 0;
            curr.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        int size = (int)nums.size();
        if (size == 0) return result;
        
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<int> used(size, 0);
        backTracking(curr, 0, size, used, nums, result);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = s.permuteUnique(nums);
    return 0;
}
