//
//  main.cpp
//  LeetCode_287_寻找重复数
//
//  Created by chx on 2020/2/16.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace stad;

class Solution {
public:
    /*
     解法 1:
     第一轮快慢指针找到重复点，第二轮双指针找重复值。
     https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode/
     
     **/
    int findDuplicate(vector<int>& nums) {
        int slow, fast;
        slow = nums[0];
        fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        int i, j;
        i = nums[0];
        j = slow;
        while (i != j) {
            i = nums[i];
            j = nums[j];
        }
        return i;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
