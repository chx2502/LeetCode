//
//  main.cpp
//  LeetCode_283
//
//  Created by chx on 2020/9/16.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0;
        for (auto &num : nums)
            if (num != 0) nums[start++] = num;
        while (start < nums.size()) nums[start++] = 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {0, 1, 0, 3, 12};
    s.moveZeroes(nums);
    return 0;
}
