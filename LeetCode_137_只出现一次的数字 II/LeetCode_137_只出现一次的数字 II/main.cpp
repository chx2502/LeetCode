//
//  main.cpp
//  LeetCode_137_只出现一次的数字 II
//
//  Created by chx on 2020/2/15.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     位运算，两个数字记录当前各位置的状态，
     (1 0) (0 1) (0 0) 分别该位对应出现 1 次，2 次，3 次，
     所有出现 3 次的位都会被清零，
     最后剩下的 1 位构成的数就是结果
     题解链接：
     https://leetcode-cn.com/problems/single-number-ii/solution/single-number-ii-mo-ni-san-jin-zhi-fa-by-jin407891/
     **/
    int singleNumber(vector<int>& nums) {
        int a, b;
        a = b = 0;
        for (auto num : nums) {
            a = a ^ (num & ~b);
            b = b ^ (num & ~a);
        }
        return a;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
#
