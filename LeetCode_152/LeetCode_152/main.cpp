//
//  main.cpp
//  LeetCode_152
//
//  Created by chx on 2020/8/18.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        
        int maxF, minF, result;
        maxF = minF = result = nums[0];
        
        for (int i = 1; i < size; i++) {
            int max_temp, min_temp, curr;
            max_temp = maxF;
            min_temp = minF;
            curr = nums[i];
            maxF = max({max_temp * curr, curr, min_temp * curr});
            minF = min({min_temp * curr, curr, max_temp * curr});
            result = max(maxF, result);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {0, 2};
    int result = s.maxProduct(nums);
    return 0;
}
