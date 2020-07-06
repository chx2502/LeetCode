//
//  main.cpp
//  LeetCode_136
//
//  Created by chx on 2020/7/6.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (auto num : nums)
            result = result ^ num;
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 2, 3, 2, 1, 4, 5, 6, 5, 4, 6};
    int result = s.singleNumber(nums);
    return 0;
}
