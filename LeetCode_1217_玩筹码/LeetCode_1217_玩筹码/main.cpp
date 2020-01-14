//
//  main.cpp
//  LeetCode_1217_玩筹码
//
//  Created by chx on 2020/1/13.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd, even;
        odd = even = 0;
        for (auto &chip : chips) {
            if (chip % 2 == 0) even += 1;
            else odd += 1;
        }
        return odd < even ? odd : even;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
