//
//  main.cpp
//  LeetCode_442_数组中重复的数据
//
//  Created by chx on 2020/2/28.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     原地实现 hash。
     对于 nums 中的每一个 0 < num < n+1，给其分配一个下标 index = |num|-1,
     对每个 num，每遇到一次 num 就使 nums[index] 变号，
     这样一来，当一个 num 再次被遍历到时，
     nums[index] < 0，此时的 |num| 即为出现 2 次的数。
     **/
    vector<int> findDuplicates(vector<int>& nums) {
        int length = (int)nums.size();
        vector<int> result;
        if (length == 0) return result;

        for (int i = 0 ; i < length; ++i) {
            int index = abs(nums[i])-1;
            if (nums[index] < 0) result.push_back(index+1);
            else nums[index] *= -1;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = s.findDuplicates(nums);
    return 0;
}
