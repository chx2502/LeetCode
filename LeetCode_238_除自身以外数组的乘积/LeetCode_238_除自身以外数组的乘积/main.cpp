//
//  main.cpp
//  LeetCode_238_除自身以外数组的乘积
//
//  Created by chx on 2020/1/20.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = (int)nums.size();

        vector<int> result(size, 1);
        int curr = 1;
        for (int i = 0; i < size; ++i) {
            result[i] = curr;
            curr *= nums[i];
        }
        curr = 1;
        for (int i = size-1; i >= 0; --i) {
            result[i] *= curr;
            curr *= nums[i];
        }

        return result;
    }
    
//    vector<int> productExceptSelf(vector<int>& nums) {
//        int length = (int)nums.size();
//        vector<int> left(length, 1);
//        vector<int> right(length, 1);
//
//        for (int i = 1; i < length; ++i) {
//            left[i] = nums[i-1] * left[i-1];
//        }
//        for (int i = length-2; i >= 0; --i) {
//            right[i] = nums[i+1] * right[i+1];
//        }
//
//        vector<int> res;
//        for (int i = 0; i < length; ++i) {
//            res.push_back(left[i] * right[i]);
//        }
//        return res;
//    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 2, 3, 4,};
    Solution s;
    vector<int> result = s.productExceptSelf(nums);
    return 0;
}
