//
//  main.cpp
//  LeetCode_31
//
//  Created by chx on 2020/9/16.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void generate(vector<int>& nums, int pre, int next) {
        if (pre < 0) {
            int i = 0;
            int j = (int)nums.size()-1;
            while (i < j) swap(nums[i++], nums[j--]);
            return;
        }
        if (nums[pre] >= nums[next]) generate(nums, pre-1, pre);
        else swap(nums[pre], nums[next]);
    }
    void nextPermutation(vector<int>& nums) {
        generate(nums, nums.size()-2, nums.size()-1);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {3, 2, 1};
    Solution s;
    s.nextPermutation(nums);
    return 0;
}
