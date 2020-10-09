//
//  main.cpp
//  LeetCode_面试题56
//
//  Created by chx on 2020/4/28.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 参考官方题解，很妙的解法。
    vector<int> singleNumbers(vector<int>& nums) {
        if (nums.size() == 2) return nums;
        vector<int> result;
        
        int XOR = 0;
        for (auto & num : nums) XOR ^= num;
        
        int judge = 1;
        while ((judge & XOR) == 0) judge = judge << 1;
        
        for (auto & num : nums)
            if ((judge & num) == 0) num *= -1;
        int temp = XOR;
        for (auto & num : nums) {
            if (num > 0) {
                temp ^= num;
            }
        }
        result.push_back(temp);
        result.push_back(temp^XOR);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
