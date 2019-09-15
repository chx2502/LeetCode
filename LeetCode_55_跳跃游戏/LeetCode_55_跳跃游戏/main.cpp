//
//  main.cpp
//  LeetCode_55_跳跃游戏
//
//  Created by 成鑫 on 2019/8/8.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = (int)nums.size();
        int right, left;
        right = length-1;
        left = right;
        while(left > 0) {
            left--;
            if (nums[left] == 0) continue;
            if (nums[left] + left >= right)
                nums[left] = 1;
            else {
                bool flag = true;
                for (int i = 1; i <= nums[left]; i++)
                    if (nums[left+i] > 0) {
                        nums[left] = 1;
                        flag = false;
                        break;
                    }
                if (flag) nums[left] = 0;
            }
        }
        if (length == 1) return true;
        if (nums[0] == 1) return true;
        else return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> test = {0};
    Solution s;
    bool result = s.canJump(test);
    return 0;
}
