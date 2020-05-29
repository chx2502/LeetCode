//
//  main.cpp
//  LeetCode_198
//
//  Created by chx on 2020/5/29.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        
        int max_odd, max_even;
        max_even = nums[0];
        max_odd = -1;
        for (int i = 2; i < size; ++i) {
            nums[i] += max(max_odd, max_even);
            if (i & 1) max_even = nums[i-1];
            else max_odd = nums[i-1];
        }
        return max(nums[size-1], nums[size-2]);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {2, 1, 1, 2};
    int result = s.rob(nums);
    return 0;
}
