//
//  main.cpp
//  LeetCode_169_求众数
//
//  Created by 成鑫 on 2019/7/7.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int size = (int)nums.size();
        int res = nums[0];
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (count == 0) res = nums[i];
            if (nums[i] == res) count++;
            else count--;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    return 0;
}
